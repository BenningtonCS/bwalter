/*
	Cat.java
	2015 March 1
	Brendon Walter
	Object Oriented Programming

	Cat class for exercise 2
*/

public class Cat {
	private String name = "Fluffy cat";
	private int age = 0;
	private String breed = "cat";

	/*
		Parameters: none
		Returns: Name of the cat as a string
	*/
	public String getName() {
		return name;
	}

	/*
		Paramters: None
		Returns: None
		Prints the values of the cat to the screen
	*/
	public void printCat() {
		System.out.printf("%s is a %d year old %s.\n", name, age, breed);
	}

	/*
		Parameters: Name (string), age (integer), and the cat's breed (string)
		Returns: None
		Set values of the cat
	*/
	public void setCat(String n, int a, String b) {
		name = n; age = a; breed = b;
		printCat();
	}

	/*
		default cat constructor
	*/
	public Cat() {
		printCat();
	}

	/*
		overriding the default constructor!!
	*/
	public Cat(String n, int a, String b) {
		setCat(n, a, b);
	}

	/*
		Parameters: none
		Returns: none
		Cause the cat to meow
	*/
	public void meow() {
		System.out.printf("mrow!\n");
	}

	/*
		Parameters: The dog the cat will encounter
		Returns: None
		The cat encounters a dog		
	*/
	public void encounterDog(Dog dog) {
		String dogName = dog.getName();
		System.out.printf("%s sees %s! %s runs away!\n", name, dogName, name);
	}
}
