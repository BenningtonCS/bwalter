/*
	Dog.java
	2015 March 1
	Brendon Walter
	Object Oriented Programming

	Dog class for exercise 2
*/

public class Dog {
    private String name = "Puppy dog";
	private int age = 0;
	private String breed = "dog";

    /*
		Parameters: none
		Returns: Name of the dog as a string
	*/
	public String getName() {
		return name;
	}

    /*
		Paramters: None
		Returns: None
		Prints the values of the dog to the screen
	*/
	public void printDog() {
		System.out.printf("%s is a %d year old %s.\n", name, age, breed);
	}

	/*
		Parameters: Name (string), age (integer), and the dog's breed (string)
		Returns: None
		Set values of the dog
	*/
	public void setDog(String n, int a, String b) {
		name = n; age = a; breed = b;
		printDog();
	}

	/*
		default dog constructor
	*/
	public Dog() {
		printDog();
	}

	/*
		overriding the default constructor!!
	*/
	public Dog(String n, int a, String b) {
		setDog(n, a, b);
	}

	/*
		Parameters: The cat the dog will encounter
		Returns: None
		The dog encounters a cat
	*/
    public void encounterCat(Cat cat) {
        String catName = cat.getName();
        System.out.printf("%s sees %s! %s runs away! %s is uninterested in %s.\n",
                           name, catName, catName, name, catName);
    }
}
