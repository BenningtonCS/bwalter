/*
    Main.java
    2015 March 1
    Brendon Walter
    Object Oriented Programming

    Exercise 2 from first assignment
*/

public class Main {
    public static void main(String[] args) {
        Cat pippen = new Cat("Pippen", 11, "orange tabby");
        Dog eleejay = new Dog("Eleejay", 15, "golden retriever");
        pippen.encounterDog(eleejay);
        eleejay.encounterCat(pippen);
    }
}
