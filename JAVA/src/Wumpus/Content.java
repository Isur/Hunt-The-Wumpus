package Wumpus;

public class Content {
	private Chamber position;
	private String name;
	private boolean isAlive;
	
	public Content() {}
	public Content(Chamber position, String name, boolean isAlive){
		this.position = position;
		this.name = name;
		this.isAlive = isAlive;
	}
	
	public int moveContent(Chamber source, Chamber destination) {
		if(destination.getContent() instanceof Player) {
			if(source.getContent() instanceof Monster) {
			((Player)destination.getContent()).die();
				return 0; 
			}
		} else if(destination.getContent() instanceof Bat) {
			return ((Bat)destination.getContent()).throwContent(source.getContent());
		} else if(destination.getContent() instanceof Monster) {
			return 0;
		}
		
		source.getContent().setPosition(destination.getChamber());
		destination.setContent(source.getContent());
		source.setContent(null);
		return 1;
	}
	
	public String getName() { return this.name; }
	public Chamber getPosition() { return this.position; }
	public boolean isAlive() {return this.isAlive;}
	public void setPosition(Chamber pos) {this.position = pos;}
	public void setAlive(boolean alive) {this.isAlive = alive;}
}
