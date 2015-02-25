/* File: 1_7.c
 * Author: Brendon Walter
 * Date: 2014.09.07
 *
 * Problem 1.7. "Using a structure to represent a time, write a function which 
 * given two time structures, t1 and t2, returns the number of minutes from t1 
 * to t2."
 */

#include <stdio.h>

typedef struct {
	int hours;
	int minutes;
} Time;

int timeDifference(Time t1, Time t2) {
	// calculate the time difference in minutes between two times

	int timediff = 0;

	if (t1.hours <= t2.hours)
		timediff += (t2.hours - t1.hours) * 60 + (t2.minutes - t1.minutes);
	else {
		// THIS ISN'T QUITE RIGHT YET!!!!
		timediff += (24 - t1.hours) * 60 + (60 - t1.minutes) + (t2.hours * 60) + t2.minutes;
	}
}

int main(void) {

	// create t1
	Time t1;
	t1.hours = 2;
	t1.minutes = 15;

	// create t2
	Time t2;
	t2.hours = 10;
	t2.minutes = 30;

	printf("%d\n", timeDifference(t1, t2));

	return 0;
}
