package edu.bennington.cs;

/**
 * Created by brendon on 3/3/15.
 */
public class Cat {
    private String name;
    private float hunger = 1;   // hunger level represented by an int

    /*
        Cat constructor
     */
    public Cat(String name) {
        this.name = name;
    }

    /*
        Parameters: none
        Returns: a string with the name of the cat
     */
    public String getName() {
        return this.name;
    }

    /*
        Parameters: None
        Returns: None
        Cause the cat to meow
     */
    public void meow() {
        System.out.println("Meow");
    }

    /*
        Parameters: integer value for the number of times the cat meows
        Returns: None
        Meow x number of times
        For loop example
     */
    public void meowXTimes(int x) {
        // if x is not a positive number, the cat doesn't meow
        if (x <= 0) return;

        for (int i=0;i<x;i++) {
            meow();
        }
    }

    /*
        Parameter: None
        Returns: None
        Eat if hungry
        While loop example
     */
    public void eat() {
        while (hunger > 0) {
            System.out.println("nom nom nom");
            hunger -= 0.1;
        }
        meow();
    }

}
