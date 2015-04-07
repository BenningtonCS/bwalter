package edu.bennington.cs;

/**
 * Object Oriented Programming
 * The Rock class.
 *
 * NOTE: YOU SHOULD NOT MODIFY THIS CLASS FOR THE PROJECT.
 *
 * A Rock is an example Critter that does nothing except devour anything
 * stupid enough to blunder into it.
 */
 
import java.awt.Color;

// A rock is an example Critter that... erodes.
public class Rock extends Critter {
	// Returns the next move for this Rock: hold still!
	public Direction getMove() {
		return Direction.CENTER;
	}
	
	// Returns the food type for this Rock: meat.
	public FoodType getFoodType() {
		return FoodType.MEAT;
	}
	
	// Returns the color of this Rock: gray.
	public Color getColor() {
		return Color.GRAY;
	}
	
	// Returns the speed of this Rock: slow.
	public Speed getSpeed() {
		return Speed.SLOW;
	}
	
	// Returns the string representation of this Rock.
	public String toString() { return "o"; }
}