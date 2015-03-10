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
	public void setCourseNumber(int number) throws InvalidCourseNumberException {
        // course number can only be a 2000 or 4000 level course
		if ((number >= 2000 && number < 3000) ||
			(number >= 4000 && number < 5000))
			this.courseNumber = number;
        
        else throw new InvalidCourseNumberException();
	}

	public void setDepartment(String d) throws InvalidDepartmentException {
        String dep = d.toUpperCase();
        switch(dep) {
            case "APA":
            case "VA":
            case "CS":
            case "PHY":
            case "CER":
            case "ES":
            case "MAT": this.department = dep;
                        break;
            default: throw new InvalidDepartmentException();
        }
	}

	public void setCourseTitle(String title) {
		this.courseTitle = title;
	}

	public void setStudents(int number) {
		if (number > 0)		// there cannot be a negative number of students
			this.students = number;
	}

	public void setBuilding(String name) throws InvalidBuildingException {

		// convert given string to uppercase for consistency
		String n = name.toUpperCase();

		// check if building is a valid building
		if (n == "DICKINSON" || n == "VAPA" || n == "CAPA" || n == "BARN" || 
			n == "COMMONS" || n == "TISHMAN" || n == "JENNINGS" ||
			n == "DEAN CARRIAGE BARN") 
			this.building = n;
		
		else throw new InvalidBuildingException();
	}

	public void setRoomNumber(int number) {
		if (number > 0)
			this.roomNumber = number;
	}

	public void setDescription(String d) {
		this.description = d;
	}
}
