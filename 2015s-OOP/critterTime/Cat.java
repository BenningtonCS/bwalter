package edu.bennington.cs;

/**
 * Cat.java
 * 2015 March 29
 * Brendon Walter
 *
 * Object Oriented Programming
 * Cat class for the Critter Time lab
 */

import java.awt.Color;

// Cat is extended from the lion class
public class Cat extends Lion {

    // call the move() function as laid out in Lion.java. There's nothing
    // fancy going on here.
    public Direction getMove() {
        return move();
    }

    // Returns the color of this cat.
    public Color getColor() {
        return Color.MAGENTA;
    }

    // Returns the speed of this cat
    public Speed getSpeed() {
        return Speed.MEDIUM;
    }

    // Returns the string representation of this cat.
    public String toString() {
        return("c");
    }
}
