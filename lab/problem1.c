/* file: problem1.c
 * date: 2014.09.14
 * author: Brendon Walter
 *
 * Fundamentals Lab problem 1
 */

#include <stdio.h>

typedef float money;


/* Takes a value of type 'money'
 * returns the number of dollars as an int
 * (e.g. input of 3.75 returns 3 dollars)
 */
int getDollas(money m) {

    return (int)m;  // casting from float to an int rounds down the
                    // number to the nearest integer.
}


/* Takes a value of type 'money'
 * Returns the amount of cents (past the decimal) as an int
 * (e.g. input of 3.75 returns 75);
 */
int getCents(money m) {

    // subtract the dollars from the total leaving a decimal. Then multiply by
    // 100 to make it an integer rather than a float.
    return (int)((m - getDollas(m))*100);
}


/* Takes no parameters, but prompts user for input
 * Returns the user input as a money variable
 */
money getMoney(void) {
    // for certain values, this returns one cent less than it should.
    // as far as I can tell, this is because it changes the value of input
    // right after it's given. (changes 100.24 to 100.239998, which then is
    // rounded down to 23.)

    float input;
    printf("How much money?\n$");
    scanf("%f", &input);
    return input;
}

/* Takes money as a parameter and prints out the amount of change in dollars, 
 * quarters, dimes, nickles, and pennies.
 */
void makeChange(money m) {
    
    // get number of dollars
    int D = getDollas(m);
    // get number of quarters
    int q = (getCents(m) - getCents(m) % 25) / 25;
    // dimes
    int d = ((getCents(m) - q*25) - (getCents(m) - q*25) % 10) / 10;
    // nickes
    int n = ((getCents(m) - q*25 - d*10) - (getCents(m) - q*25 - d*10) % 5) / 5;
    //pennies
    int p = getCents(m) - q*25 - d*10 - n*5;
    
    printf("%d dollars, %d quarters, %d dimes, %d nickles, and %d pennies.\n",
            D, q, d, n, p);
}

int main(void) {

    money a = getMoney();   // gets user input
    int d = getDollas(a);   // separate input into just dollars
    int c = getCents(a);    // separate input into just cents
    printf("dollas: %d\ncents: %d\n", d, c);    // print output
    makeChange(a);          // separate input into change
}
