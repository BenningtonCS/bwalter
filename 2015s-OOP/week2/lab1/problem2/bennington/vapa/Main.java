package edu.bennington.vapa;

import edu.bennington.cs.Cat; // intellij yells at you if you don't import this
                            // when you try to create a cat

/**
 * Created by brendon on 3/3/15.
 */
public class Main {

    public static void main(String[] args) {
        Cat kitty = new Cat("Fluff");
        kitty.meow();
        System.out.println(kitty.getName());
    }
}
