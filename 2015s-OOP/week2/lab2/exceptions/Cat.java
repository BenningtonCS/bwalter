import java.applet.*;
import java.net.*;

/*
    Cata.java
    2015 March 9
    Brendon Walter

    Lab 2: Exceptions
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
    public void meow() throws MalformedURLException {
        try {
            AudioClip clip = Applet.newAudioClip(new URL("file:meow.wav"));
            clip.play();
        } catch (MalformedURLException e) {
            throw e;
        }
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
            try { 
                meow(); 
            } catch (MalformedURLException e) { 
                System.out.println(e);
            }
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
        try {
            meow();
        } catch (MalformedURLException e) {
            System.out.println(e);
        }
    }

}
