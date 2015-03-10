/*
    BenningtonStudent.java
    2015 March 8
    Brendon Walter

    BenningtonStudent class inherited from Student class from lab2
*/

public class BenningtonStudent extends Student {
    String PlanTitle;
    String Advisor;

    public BenningtonStudent() { };

    /*
    ===========================================================================
        G E T T E R S
    ===========================================================================
    */
    public String getPlanTitle() { return this.PlanTitle; }
    public String getAdvisor() { return this.Advisor; }


    /*
    ===========================================================================
        S E T T E R S
    ===========================================================================
    */
    public void setPlanTitle(String title) {
        this.PlanTitle = title;
    }

    public void setAdvisor(String name) {
        this.Advisor = name;
    }
}
