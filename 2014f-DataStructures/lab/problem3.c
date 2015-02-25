/* file: problem3.c
 * date: 2014 September 22
 * author: Brendon Walter
 *
 * Fundamentals Lab: Problem 3
 */

#include <stdio.h>

typedef struct {
    int dollars;
    int cents;
} Money;

typedef struct {
    int dollars;
    int quarters;
    int dimes;
    int nickles;
    int pennies;
} Change;

Money myMoney;  // make Money struct to be used through out the entire program

/* Recieves the total amount of money as a float as well as a pointer to an 
 * integer.
 * Typecasts the float to an int and assigns the value to the pointer as the
 * total amount of money in dollars. 
 */
void getDollars(float amount, int* d) {  
    *d = (int)amount;
}

/* Does the same as getDollars(), but subtracts the amount in dollars from the
 * total amount and multiplies it by 100. Typecasts it into an integer and 
 * assigns it to the pointer.
 */
void getCents(float amount, int* c) {
    int d = (int)amount;
    *c = (int)((amount - d) * 100);
}

/* Uses user input as to get the amount of money. Uses getDollars() and
 * getCents() to break the input into dollars and cents, and then puts them
 * into the Money struct.
 */
void getMoney() {

    // get amount of money from user
    float m;
    printf("How much money?\n$");
    scanf("%f", &m);    // this will still sometimes interrpret input as being
                        // one cent less than it should be. Still don't know
                        // why. Still don't know a fix.

    // calls getDollars() and getCents() and assigns output to two integers
    int dollars, cents;
    getDollars(m, &dollars);
    getCents(m, &cents);

    // puts the information into the Money struct
    myMoney.dollars = dollars;
    myMoney.cents = cents;
}

/* Takes a pointer to a Money struct, divides the cents into quarters, dimes, 
 * etc. and puts the output into a Change struct which is then returned. 
 */
Change makeChange(Money m) {

    int D = m.dollars;
    int c = m.cents;
    // get number of quarters
    int q = (c - c % 25) / 25;
    // dimes
    int d = ((c - q*25) - (c - q*25) % 10) / 10;
    // nickles
    int n = ((c - q*25 - d*10) - (c - q*25 - d*10) % 5) / 5;
    // pennies
    int p = c - q*25 - d*10 - n*5;

    // put the values calculated above into the Change struct
    Change myChange;
    myChange.dollars = D;
    myChange.quarters = q;
    myChange.dimes = d;
    myChange.nickles = n;
    myChange.pennies = p;

    return myChange;
}

/* Takes a pointer to a Change struct and adds the coins up to come up with
 * a total amount. Puts information into a Money struct and returns it.
 */
Money makeMoneyFromChange(Change *c) {
    Money money;
    
    money.dollars = c -> dollars;
    money.cents = c->quarters*25 + c->dimes*10 + c->nickles*5 + c -> pennies;

    return money;
}

int main(void) {

    Money m;
    Change c;

    // demonstrates ability of each function
    getMoney();
    printf("You said: %d.%d\n", myMoney.dollars, myMoney.cents);
    c = makeChange(myMoney);
    printf("That is %d dollar(s), %d quarters, %d dimes, %d nickles, and %d pennies.\n", c.dollars, c.quarters, c.dimes, c.nickles, c.pennies);
    m = makeMoneyFromChange(&c);
    printf("Which makes %d dollar(s) and %d cents.\n", m.dollars, m.cents);
    
    return 0;
}
