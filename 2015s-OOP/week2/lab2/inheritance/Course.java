public class Course {
	private int courseNumber;		// number for the course
	private String department;		// department the course is a part of
	private String courseTitle;		// title of the course
	private int students;			// students enrolled in the course
	private String building;		// building the class will be in
	private int roomNumber;			// room number
	private String description;		// description of the course

	public Course() { };

	/*
	===========================================================================
		G E T T E R S
	===========================================================================
	*/
	public int getCourseNumber() { return this.courseNumber; }
	public String getDepartment() { return this.department; }
	public String getCourseTitle() { return this.courseTitle; }
	public int getStudents() { return this.students; }
	public String getBuilding() { return this.building; }
	public int getRoomNumber() { return this.roomNumber; }
	public String description() { return this.description; }
	
	/*
	===========================================================================
		S E T T E R S
	===========================================================================
	*/
	public void setCourseNumber(int number) {
		// course number can only be a 2000 or 4000 level course
		if ((courseNumber >= 2000 && courseNumber < 3000) ||
			(courseNumber >= 4000 && courseNumber < 5000))
			this.courseNumber = number;

		else return;		// throw exception at some point

	}

	public void setDepartment(String d) {
		/*
			switch thing???
		*/
	}

	public void setCourseTitle(String title) {
		this.courseTitle = title;
	}

	public void setStudents(int number) {
		if (number > 0)		// there cannot be a negative number of students
			this.students = number;
	}

	public void setBuilding(String name) {

		// convert given string to uppercase for consistency
		String n = name.toUpperCase();
		this.building = n;

		// check if building is a valid building
		if (n == "DICKINSON" || n == "VAPA" || n == "CAPA" || n == "BARN" || 
			n == "COMMONS" || n == "TISHMAN" || n == "JENNINGS" ||
			n == "DEAN CARRIAGE BARN") 
			this.building = n;
		
		else return;	// throw an exception
	}

	public void setRoomNumber(int number) {
		if (number > 0)
			this.roomNumber = number;
	}

	public void setDescription(String d) {
		this.description = d;
	}
}
