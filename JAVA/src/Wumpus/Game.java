package Wumpus;

import java.util.Random;
import java.util.Scanner;

public class Game {
	private int status;
	private String name;
	private Chamber chamb;
	private Player player = null;
	private Monster monster = null;
	static Scanner scan;	
	
	
	private void prepareMap() {
		
		Random rand = new Random();
		int randomPosition, randomFloor, randomBat;
		chamb = new Chamber(1);
		for(int i = 2; i <= 20; i++) { 
			chamb = chamb.addChamber(new Chamber(i));
			randomFloor = rand.nextInt(100);
			randomBat = rand.nextInt(100);
			if(randomFloor < 10) chamb.setFloor(false);
			else if(randomBat < 10) chamb.setContent(new Bat(chamb, "Bat", true));
		}
		chamb = chamb.findFirst();
		chamb.setConnection(0, chamb.shift(20));
		chamb.shift(20).setConnection(2, chamb.shift(1));
		for(int i = 2; i <= 19; i++) chamb.shift(i).setConnection(1, chamb.shift(21-i));;
		chamb.setConnection(1, chamb.shift(10));
		chamb.shift(20).setConnection(1, chamb.shift(11));
		chamb.shift(10).setConnection(1, chamb.shift(1));
		chamb.shift(11).setConnection(1, chamb.shift(20));
		
		do{
			randomPosition = rand.nextInt(20)+1;
			player = new Player(chamb.shift(randomPosition), name, true);
		}while(chamb.shift(randomPosition).getContent() != null || chamb.shift(randomPosition).getFloor() == false);
		chamb.shift(randomPosition).setContent(player);
		
		do{
			randomPosition = rand.nextInt(20)+1;
			monster = new Monster(chamb.shift(randomPosition), "Wumpus", true);
		}while(chamb.shift(randomPosition).getContent() != null);		
		
		chamb.shift(randomPosition).setContent(monster);
		
		chamb.debug();
	}
	
	private void actualGame() {
		int temp;
		System.out.println("\n");
		System.out.print(player.getName() + ", KILL THE WUMPUS!");	
		String action;
		while(player.isAlive() && monster.isAlive()) {
			System.out.println();
			System.out.println(player.getPosition().getNumber());
			System.out.println(monster.getPosition().getNumber());
			chamb = player.getPosition();
			chamb.showInfo();
			System.out.println("\nMove: m[chamber nubmer], Shoot: s[chamber number], Debug: d.");
			action = scan.nextLine();
			if(action.length() == 1) {
				if(action.matches("d")) chamb.debug();
			} else if(action.length() <= 3) {
				temp = Integer.parseInt(action.substring(1));
				if(temp <= 20) {
					if(	temp == chamb.getAdjacent(0).getNumber() ||
						temp == chamb.getAdjacent(1).getNumber() ||
						temp == chamb.getAdjacent(2).getNumber()) {
						System.out.println(temp);
						if(action.startsWith("m")) {
							status = player.moveContent(chamb, chamb.find(temp));
						}else if(action.startsWith("s")) {
							player.shoot(chamb.find(temp), monster);
						}else System.out.println("WRONG COMMAND");
					}else System.out.println("WRONG CHAMBER");
				}else System.out.println("WRONG CHAMBER");
				
			}else System.out.println("TOO LONG STRING");
			if(status == 0) {
				System.out.print("You died.");
				break;
			};
		}
	}
	
	
	public void newGame() {
		System.out.println("Tell us your name: ");
		name = scan.nextLine();
		System.out.println("Nice to meet you " + name + ". You have 5 arrows. Wumpus is somewhere. Be careful! Bats and rooms without floor here!");
		prepareMap();
		actualGame();
		
	}
	
	
	public Game() {
		scan = new Scanner(System.in);
		System.out.println("New Game started...");
		status = 1;
	}
	
}
