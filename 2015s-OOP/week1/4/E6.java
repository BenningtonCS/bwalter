/*
	E6.java
	2015 March 1
	Brendon Walter
	Object Oriented Programming

	"Exercise 6: Write a program that includes and calls the storage() method defined as a code fragment in this chapter."
*/

class Store {
	int storage(String s) {
		return s.length() * 2;
	}
}

public class E6 {
	public static void main(String[] args) {
		Store st = new Store();
		int result = st.storage("much string");
		System.out.printf("%d\n", result);
	}
}
