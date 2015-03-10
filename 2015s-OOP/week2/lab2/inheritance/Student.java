public class Student {
	private String name;		// student's name
	private int birthdate;		// dob (ex: 19940915 for 1994 Sept 15)
	private int term;			// student's current term
	private float GPA;			// student's GPA

	public Student() { };

	/*
	===========================================================================
		G E T T E R S
	===========================================================================
	*/
	public String getName() { return this.name; }
	public int getBirthdate() { return this.birthdate; }
	public int getTerm() { return this.term; }
	public float getGPA() { return this.GPA; }

	/*
	===========================================================================
		S E T T E R S
	===========================================================================
	*/

	public void setName(String n) {
		this.name = n;
	}

	public void setBirthdate(int dob) {

		// check each part of the value to make sure it's valid!!

		this.birthdate = dob;
	}

	public void setTerm(int t) {
		if (t < 1 || t > 8) return;		// throw exception
		else this.term = t;
	}


	public void setGPA(float gpa) {
		if (gpa < 0 || gpa > 4) return;	// throw exception
		else this.GPA = gpa;
	}
}
