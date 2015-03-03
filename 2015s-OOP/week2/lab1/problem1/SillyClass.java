package edu.bennington.cs;

/**
 * Created by acencini on 3/1/15.
 *
 * This class has a number of simple errors in it.  Your job
 * is to fix those errors, such that the Main class can use
 * SillyClass - in other words, fix the errors so the project
 * will compile and run without error!
 *
 * Also, add comments to each function and member to indicate
 * what each thing does.  When done, check this and Main.java
 * into your GitHub repo (you will not receive credit if this is
 * not done).
 *
 */
public class SillyClass {

    private String secretString;
    public static String magicString = "magic";
    public String otherString;

    private void printSomething(String thingToPrint) {
        System.out.println(thingToPrint);
    }

    private void getSecretString() {
        System.out.println(this.secretString);
    }


    public SillyClass(String secret) {
        this.secretString = secret;
        this.otherString = secret.toUpperCase();
    }

    public void callPrintSomething(String something) {
        this.printSomething(something);
    }

    public void callPrintABunchOfTimes(int numTimes, String message) {
        for (int i=0; i<numTimes; i++) {
            this.printSomething(message);
        }
    }

    public String getAString() {
        return this.secretString;
    }

    public String printHello() {
        System.out.println(magicString);
        return this.otherString;
    }

}
