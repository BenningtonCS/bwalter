/* file: problem2.c
 * date: 2014.09.16
 * author: Brendon Walter
 * 
 * Fundamentals Lab problem 2
 */

#include <stdio.h>

typedef struct {
    int dollas;
    int cents;
} Money;


/* Takes a float as a parameter and type-casts it into a int, wich is then
 * returned as the number of dollars.
 */
int getDollas(float m) {
    return (int)m;
}

/* Takes a float as a parameter, uses getDollas() to subtract the integer from
 * the float (leaving only decimals), then multiplies it by 100 and casts it
 * to an integer which is then returned as the amount of cents.
 */
int getCents(float m) {
    return (int)((m - getDollas(m))*100);
}

/* Takes an amount of money as a float, seperates it into dollars and cents,
 * and then puts that into a struct which is then returned.
 */
Money makeMoney(float m) {
    Money money;

    money.dollas = getDollas(m);    // get amount of dollars
    money.cents = getCents(m);      // get amount of cents

    return money;                   // return struct
}

/* Uses scanf to get user input for the amount of money. Returns the output
 * of makeMoney() as a way of returning a struct.
 */
Money getMoney(void) {
    float m;

    printf("How much money?\n");
    scanf("%f", &m);        // scanf will interpret some decimal places as 
                            // being slightly smaller than they actually are... 
                            // this causes the program to return a value that 
                            // is one cent less than what it should be.

    return makeMoney(m);
}

/* Takes a money struct as a parameter and prints out the amount of change in
 * dollars, quarters, dimes, nickles, and pennies.
 */
void makeChange(Money m) {
    // get amount in dollars and cents
    int D = m.dollas;
    int c = m.cents;
    // get number of quarters
    int q = (c - c % 25) / 25;
    // dimes
    int d = ((c - q*25) - (c - q*25) % 10) / 10;
    // nickles
    int n = ((c - q*25 - d*10) - (c - q*25 - d*10) % 5) / 5;
    // pennies
    int p = c - q*25 - d*10 - n*5;

    // print it all out in a nice format
     printf("%d dollars, %d quarters, %d dimes, %d nickles, and %d pennies.\n",
            D, q, d, n, p);
}

int main(void) {
    
    Money m = getMoney();   // take user input to put money in struct
    int d = m.dollas;       // use struct to get number in dollars
    int c = m.cents;        // and the number in cents
    printf("dollas: %d\t cents: %d\n", d, c);   // prints it out
    makeChange(m);          // and gives how much change it takes to make up
                            // the same amount of money
}
