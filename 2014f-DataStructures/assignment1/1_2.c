/* File: 1_2.c
 * Author: Brendon Walter
 * Date: 2014.09.06
 *
 * Problem 1.2. "Write a program to read names and phone numbers into a 
 * structure array. Request a name and print the person's phone number. Use 
 * binary search to look up the name."
 */

#include <stdio.h>
#define MAXNUMBERS 5 

typedef struct {
    char name[31];
    long number;
} Phone;

int search(char name[], Phone list[]) {
    int j;
    for(j=0;j<MAXNUMBERS;j++) {
        if(strcmp(name, list[j].name) == 0) {
            printf("%s's phone number: %lu\n", list[j].name, list[j].number);
        }
    }
    return -1;
}

int main(void) {

    Phone numbers[MAXNUMBERS];

    FILE* in = fopen("1_2.txt", "r");

    int i;
    for(i=0;i<MAXNUMBERS;i++) {
        fscanf(in, "%s%lu", numbers[i].name, &numbers[i].number);

        //printf("%s, %lu\n", numbers[i].name, numbers[i].number);
    }

    search("CrazyRussianGirls", numbers);
	search("Ramuntos", numbers);
	search("SouthStreetCafe", numbers);
	search("Fiddlehead", numbers);
	search("BenningtonCollege", numbers);


    return 0;
}
