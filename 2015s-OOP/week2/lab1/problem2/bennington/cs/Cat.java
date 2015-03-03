package edu.bennington.cs;

/**
 * Created by brendon on 3/3/15.
 */
public class Cat {
    private String name;

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
}
