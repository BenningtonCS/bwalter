package edu.bennington.cs;

/**
 * Lion.java
 * 2015 March 29
 * Brendon Walter
 *
 * Object Oriented Programming
 * Lion class for the Critter Time lab
 */

import java.awt.Color;
import java.util.Random;

// Lion sleeps and moves
public class Lion extends Critter {

    private boolean isSleeping = false; // check if lion is asleep
    private int nextSleep = 8;          // moves until next sleep
    private int sleepTime = 0;          // how long the lion has been sleeping
    private int steps = 0;          // how many steps the cat has taken since it changed directions
    private int dir = randomNum(4); // randomly generated number to tell which direction its going


    // generate a random number between 0 and the number given
    private int randomNum(int num) {
        Random rn = new Random();
        return rn.nextInt(num);
    }

    // function to determine which way the lion moves.
    // also used for the cat's movement
    protected Direction move() {
        // if it's taken 4 steps in this direction
        if (steps >= 4) {
            this.steps = 0;             // reset steps
            this.dir = randomNum(4);     // choose new direction
        } else this.steps++;            // otherwise, take another step

        // return which way it moves
        if (dir == 0) return Direction.NORTH;
        if (dir == 1) return Direction.EAST;
        if (dir == 2) return Direction.SOUTH;
        else return Direction.WEST;

    }

    // get the direction of movement of the lion
    public Direction getMove() {
        if (nextSleep == 0) {       // if it's time to sleep
            isSleeping = true;      // start sleeping
            sleepTime = randomNum(5);   // choose time to be asleep for
            nextSleep = 8;          // and reset time
        }

        if (!isSleeping) {          // if the lion isn't asleep
            nextSleep--;            // decrease time until next sleep
            return move();          // move somewhere
        } else {                    // if the lion is asleep
            if (sleepTime != 0) {   // so long as there's still time to sleep
                sleepTime--;        // sleep
            } else isSleeping = false;   // otherwise, wake up
            return Direction.CENTER;
        }
    }



    // Returns the food type for this lion: meat
    public FoodType getFoodType() {
        return FoodType.MEAT;
    }

    // Returns the color of this lion.
    public Color getColor() {
        return Color.ORANGE;
    }

    // Returns the speed of this lion
    public Speed getSpeed() {
        return Speed.SLOW;
    }

    // Returns the string representation of this lion
    public String toString() {
        if (!isSleeping) return "L";    // the lion isn't asleep
        else return "Z";                // the lion is asleep
    }
}