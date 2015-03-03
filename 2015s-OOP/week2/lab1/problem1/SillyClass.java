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

	/*
		Parameters: String you want to print
		Returns: None
		Print a string to the console
	*/
    private void printSomething(String thingToPrint) {
        System.out.println(thingToPrint);
    }

	/*
		Parameters: None
		Returns: None
		Print a predetermined secret string
	*/ 
    private void getSecretString() {
        System.out.println(this.secretString);
    }


	/*
		Silly class constructor
		Converts the string given to it to uppercase and stores both
	*/
    public SillyClass(String secret) {
        this.secretString = secret;
        this.otherString = secret.toUpperCase();
    }

	/*
		Parameters: String you want to print
		Returns: None
		Calls printSomething to print your string to the screen
	*/
    public void callPrintSomething(String something) {
        this.printSomething(something);
    }

	/*
		Parameters: Number of times you want message to print, message
		Returns: None
		Prints your message a number of times
	*/
    public void callPrintABunchOfTimes(int numTimes, String message) {
        for (int i=0; i<numTimes; i++) {
            this.printSomething(message);
        }
    }


	/*
		Parameters: None
		Returns: A string
		Returns a secret string to the user
	*/
    public String getAString() {
        return this.secretString;
    }


	/*
		Parameters: None
		Returns: A string
		Prints out a magic string to the terminal and returns a stored 
			string
	*/
    public String printHello() {
        System.out.println(magicString);
        return this.otherString;
    }

}
