public class Main {
	public static void main(String[] args) {
        Course oop = new Course();
        oop.setCourseTitle("Object Oriented Programming");
        try {
            oop.setDepartment("CS");
            oop.setCourseNumber(4153);
        } catch (InvalidDepartmentException e) {
            System.out.println(e);
        } catch (InvalidCourseNumberException e) {
            System.out.println(e);
        }
        
        System.out.println(oop.getCourseTitle());
        System.out.println(oop.getDepartment());
        System.out.println(oop.getCourseNumber());
    }
}
