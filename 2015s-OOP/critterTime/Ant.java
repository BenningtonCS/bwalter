package edu.bennington.cs;

/**
 * Ant.java
 * 2015 March 24
 * Brendon Walter
 *
 * Object Oriented Programming
 * Ant class for the Critter Time lab
 */

import java.awt.Color;

// An ant move quickly and eats grass
public class Ant extends Critter {

    // private attributes for its movement
    private boolean stepsNorth;     // is it moving northward or southward
    private char lastMove = 'a';    // what was the last direction the ant moved

    public Ant(boolean stepsNorth) {
        this.stepsNorth = stepsNorth;
    }

    // check it it's the ant's first step
    private boolean firstStep() {
        if (lastMove == 'a') return true;
        return false;
    }

    // makes the getMove() code prettier. This returns which direction it's
    // moving as well as updates it's last step
    private Direction move(char d) {
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

    // get the direction of movement of the ant: n, e, n, e, etc
    // or s, w, s, w...
    public Direction getMove() {

        // if this is the ant's first step
        if (firstStep()) {
            // check if it's moving northward or southward and move appropriately
            if (stepsNorth) return move('n');
            else return move('s');
        }

        // check what the last move was. If north, then move east next
        if (lastMove == 'n') return move('e');
        if (lastMove == 'e') return move('n');
        if (lastMove == 's') return move('w');
        else return move('s');

    }

    // Returns the food type for this Ant: grass.
    public FoodType getFoodType() {
        return FoodType.GRASS;
    }

    // Returns the color of this Ant: black.
    public Color getColor() {
        return Color.BLACK;
    }

    // Returns the speed of this Ant: slow.
    public Speed getSpeed() {
        return Speed.FAST;
    }

    // Returns the string representation of this Ant.
    public String toString() { return "%"; }
}