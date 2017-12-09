package Wumpus;

public class Chamber {
	private int number;
	private Chamber n[];
	private Content con;
	private boolean floor;
	
	public Chamber(int number) {
		this.number = number;
		this.n = new Chamber[3];
		this.n[0] = null;
		this.n[1] = null;
		this.n[2] = null;
		this.con = null;
		this.floor = true;
	}
	// SETTERS
	public void setConnection(int connect, Chamber c) { this.n[connect] = c; }
	public void setFloor(boolean floor) { this.floor = floor; }
	public void setContent(Content con) { this.con = con; }
	// GETTERS
	public int getNumber() { return this.number; }
	public Chamber getAdjacent(int n) { return this.n[n]; }
	public Content getContent() { return this.con; }
	public boolean getFloor() { return this.floor; }
	public Chamber getChamber() { return this; }
	
	public Chamber shift(int n) {
		if(n == 1) return this;
		else return this.n[2].shift(n-1);
	}
	
	public Chamber find(int n) {
		if(this.getNumber() == n) return this;
		else return this.getAdjacent(2).find(n);
	}
	
	public Chamber findFirst() {
		if(this.getNumber() == 1) return this;
		else return this.n[0].findFirst();		
	}
	
	public Chamber addChamber(Chamber c) {
		this.n[2] = c;
		c.n[0] = this;
		return c;
	}
	
	public void debug() {
		for(int i = 1; i <= 20; i++) {
			System.out.print("\nChamber " + this.shift(i).getNumber());
			System.out.print("|" + this.shift(i).getAdjacent(0).getNumber() + "|");
			System.out.print("|" + this.shift(i).getAdjacent(1).getNumber() + "|");
			System.out.print("|" + this.shift(i).getAdjacent(2).getNumber() + "|");
			if(this.shift(i).getContent() != null)System.out.print("|" + this.shift(i).getContent().getName() + "|");
			System.out.print("|" + this.shift(i).getFloor() + "|");
		}
	}
	
	public void showInfo(){
		System.out.println("\nYou are in chamber: " + this.getNumber() + ", you have: " + ((Player)this.getContent()).getArrows() + " arrows and adjacent chambers are: ");
		for(int i = 0;i < 3; i++ ) System.out.print("|" + this.getAdjacent(i).getNumber() + "|");
		for(int i = 0;i < 3; i++ ) {
			if(this.getAdjacent(i).getContent() instanceof Monster) System.out.print("| You feel something...|");
			if(this.getAdjacent(i).getContent() instanceof Bat) System.out.print("| You hear something... |");
			if(this.getAdjacent(i).getFloor() == false) System.out.print("| You feel draft... |");
		}
	}
	
}
