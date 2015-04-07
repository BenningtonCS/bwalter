package edu.bennington.cs;

/**
 * Bird.java
 * 2015 March 24
 * Brendon Walter
 *
 * Object Oriented Programming
 * Bird class for the Critter Time lab
 */

import java.awt.Color;

// A bird moves clockwise in the shape of a 3x3 square
public class Bird extends Critter {

    private char lastMove = 'n';
    private int moveCount = 0;

    private Direction move(char d) {
        moveCount++;
        if (d == 'n') {
            lastMove = 'n';
            return Direction.NORTH;
        } else if (d == 'e') {
            lastMove = 'e';
            return Direction.EAST;
        } else if (d == 's') {
            lastMove = 's';
            return Direction.SOUTH;
        } else {
            lastMove = 'w';
            return Direction.WEST;
        }
    }

    public Direction getMove() {
        if (moveCount < 3) {
            if (lastMove == 'n') return move('n');
            else if (lastMove == 'e') return move('e');
            else if (lastMove == 's') return move('s');
            else return move('w');
        } if (moveCount == 3) {
            moveCount = 0;      // reset move count
            if (lastMove == 'n') return move('e');
            else if (lastMove == 'e') return move('s');
            else if (lastMove == 's') return move('w');
            else return move('n');
        }

        return Direction.CENTER;
    }

    // Returns the food type for this Rock: meat.
    public FoodType getFoodType() {
        return FoodType.GRASS;
    }

    // Returns the color of this Rock: gray.
    public Color getColor() {
        return Color.RED;
    }

    // Returns the speed of this Rock: slow.
    public Speed getSpeed() {
        return Speed.FAST;
    }

    // Returns the string representation of this Rock.
    public String toString() {
        if (lastMove == 'n') return "^";
        else if (lastMove == 'e') return ">";
        else if (lastMove == 's') return "v";
        else return "<";
    }
}