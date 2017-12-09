package Wumpus;

import java.util.Random;

public class Bat extends Content{

	public Bat(Chamber position, String name, boolean isAlive)  {
		super(position, name, isAlive);
		}
	


	public int throwContent(Content con) {
		Random rand = new Random();
		int randomPosition = rand.nextInt(20)+1;
		System.out.println("Bat threw you to Chamber " + randomPosition);
		return con.moveContent(con.getPosition(), this.getPosition().findFirst().shift(randomPosition));
	}
}
