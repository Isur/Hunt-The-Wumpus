package Wumpus;
import java.util.Random;
public class Monster extends Content {

	public Monster(Chamber position, String name, boolean isAlive)  {
		super(position, name, isAlive);
		}
	public void killMonster() {
		this.setAlive(false);
		System.out.println("Monster died... YOU WON!");
	}
	public void movement(Chamber playerPosition) {
		for(int i = 0; i < 3; i++) {
			if(this.getPosition().getAdjacent(i).equals(playerPosition)) {
				System.out.println("He know where are you...");
				this.moveContent(this.getPosition(), this.getPosition().getAdjacent(i));
				return;
			}
		}
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(this.getPosition().getAdjacent(i).getAdjacent(j).equals(playerPosition)) {
					System.out.println("He know where are you...");
					this.moveContent(this.getPosition(), this.getPosition().getAdjacent(i));
					return;
				}
			}
		}
		Random randPos = new Random();
		this.moveContent(this.getPosition(), this.getPosition().getAdjacent(randPos.nextInt(3)));
	}
}
