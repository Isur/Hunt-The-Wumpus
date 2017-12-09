package Wumpus;

public final class Player extends Content{
private int arrows;
	public Player(Chamber position, String name, boolean isAlive)  {
		super(position, name, isAlive);
		this.arrows = 5;
	}
	public int getArrows() {return this.arrows;}
	public void shoot(Chamber chamb, Monster monster) {
		if(this.arrows > 0) {
			this.arrows--;
			if(chamb.getContent() instanceof Monster) {
				((Monster)chamb.getContent()).killMonster();
			}else {
				monster.movement(this.getPosition());
			}
		}
	}
	public void die() {this.setAlive(false); System.out.println("You die...");}

}
