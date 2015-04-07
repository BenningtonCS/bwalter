package edu.bennington.cs;

import java.awt.*;
import java.util.Random;

/**
 * Spriggan.java
 * 2015 April
 * Brendon Walter
 *
 * A spriggan is a small but fast creature...
 */
public class Spriggan extends Critter {

    // look in a given direction for an enemy
    private boolean lookForEnemy(Direction dir) {
        if (!" ".equals(info.getNeighbor(dir)) &&   // if neighbor isn't empty
            !"\"".equals(info.getNeighbor(dir)))    // and it isn't grass
            return true;                            // then there's an enemy
        return false;
    }

    // look in a given direction for grass
    private boolean lookForFood(Direction dir) {
        if ("\"".equals(info.getNeighbor(dir)))
            return true;
        return false;
    }

    // look in a given direction for another spriggan
    private boolean lookForSpriggan(Direction dir) {
        if ("s".equals(info.getNeighbor(dir)))
            return true;
        return false;
    }


    // generate a random number between 0 and the number given
    private Direction randomDir(int num) {
        Random rn = new Random();
        if (rn.nextInt(num) == 0) return Direction.NORTH;
        if (rn.nextInt(num) == 1) return Direction.EAST;
        if (rn.nextInt(num) == 2) return Direction.SOUTH;
        return Direction.WEST;
    }

    // Returns the next move
    public Critter.Direction getMove() {

        // check a direction for an enemy. If there's on there, move the other way
        if (lookForEnemy(Direction.NORTH)) return Direction.SOUTH;
        if (lookForEnemy(Direction.SOUTH)) return Direction.NORTH;
        if (lookForEnemy(Direction.EAST)) return Direction.WEST;
        if (lookForEnemy(Direction.WEST)) return Direction.EAST;

        // if there are no enemies, then look for another spriggan
        if (lookForFood(Direction.NORTH)) return Direction.NORTH;
        if (lookForFood(Direction.SOUTH)) return Direction.SOUTH;
        if (lookForFood(Direction.EAST)) return Direction.EAST;
        if (lookForFood(Direction.WEST)) return Direction.WEST;

        // if none of the above, look for food
        if (lookForFood(Direction.NORTH)) return Direction.NORTH;
        if (lookForFood(Direction.SOUTH)) return Direction.SOUTH;
        if (lookForFood(Direction.EAST)) return Direction.EAST;
        if (lookForFood(Direction.WEST)) return Direction.WEST;

        // otherwise, move in a random direction
        return randomDir(4);
    }

    // Returns the food type
    public Critter.FoodType getFoodType() {
        return Critter.FoodType.GRASS;
    }

    // Returns the color
    public Color getColor() {
        return Color.GREEN;
    }

    // Returns the speed
    public Critter.Speed getSpeed() {
        return Critter.Speed.FAST;
    }

    // Returns the string representation
    public String toString() { return "s"; }
}

