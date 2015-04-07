package edu.bennington.cs;
/**
 * Object Oriented Programming
 * The Lemming class.
 *
 * NOTE: YOU SHOULD NOT MODIFY THIS CLASS FOR THE PROJECT.
 *
 * A Lemming is an example Critter that blindly marches east (usually
 * to its doom).
 */
 
import java.awt.Color;

// A Lemming is an example Critter that always marches east.
public class Lemming extends Critter {
	// Returns the next move this Lemming: always east.
	public Direction getMove() {
		return Direction.EAST;
	}
	
	// Returns the food type for this Lemming: meat.
	public FoodType getFoodType() {
		return FoodType.GRASS;
	}
	
	// Returns the color for this Lemming: blue.
	public Color getColor() {
		return Color.BLUE;
	}
	
	// Returns the speed of this Lemming: medium.
	public Speed getSpeed() {
		return Speed.FAST;
	}
	
	// Returns the String representation of this Lemming.
	public String toString() {
		return "e";
	}
}