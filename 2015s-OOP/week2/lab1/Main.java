package edu.bennington.cs;

public class Main {

    public static void main(String[] args) {
        SillyClass silly = new SillyClass("this is the secret");
        silly.callPrintABunchOfTimes(4, "four");
        silly.printHello();
        silly.callPrintSomething("some thing");
        silly.callPrintSomething(silly.getAString());
        silly.callPrintSomething(SillyClass.magicString);
        System.out.println(silly.otherString);
    }
}
