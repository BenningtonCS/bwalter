/*
	E8.java
	2015 March 1
	Brendon Walter
	Object Oriented Programming

	"Exercise 8: Write a program that demonstrates that, no matter how many objects you create of a particular class, there is only one instance of a particular static field in that class."
*/

class Example8 {
	static int staticVal;
}

public class E8 {
	public static void main(String[] args) {
		Example8 a = new Example8(),
				 b = new Example8();

		// print out values
		System.out.printf("a.staticVal: %d\tb.staticVal: %d\n",
						   a.staticVal, b.staticVal);

		// attempt to change value
		System.out.printf("a.staticVal changed to 2, b.staticVal changed to 4.\n");
		a.staticVal = 2;
		b.staticVal = 4;

		// print result of the change
		System.out.printf("a.staticVal: %d\tb.staticVal: %d\n",
						   a.staticVal, b.staticVal);
	}
}
