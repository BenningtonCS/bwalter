/*
    E10.java
    2015 March 1
    Brendon Walter
    Object Oriented Programming

    "Exercise 10: Write a program that prints three arguments taken from the command line. To do this, you'll need to index into the command-line array of Strings."
*/

public class E10 {
    public static void main(String[] args) {
        for (int i=0;i<3;i++)
            System.out.printf("%s\n", args[i]);
    }
}
