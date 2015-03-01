/*
	E1.java
	2015 March 1
	Brendon Walter
	Object Oriented Programming

	"Exercise 1: Create a class containing an int and a char that are not initialized, and print their values to verify that Java performs default initialization."
*/

class Example1 {
	int i;
	char c;
}

public class E1 {
	public static void main(String[] args) {
		Example1 e = new Example1();

		// print integer default values for i and c
		System.out.printf("%d, %d\n", e.i, (int)e.c);
	}
}
