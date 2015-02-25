/* File: 1_8.c
 * Author: Brendon Walter
 * Date: 2014.09.07
 *
 * Problem 1.8. "A length, specified in meters and centimeters, is represented 
 * by two integers. ... Using a structure to represent a length, write functions 
 * to compare, add, and subtract two lengths."
 */

#include <stdio.h>

typedef struct {
	int m;
	int cm;
} Length;

Length add(Length l1, Length l2) {
	// add two lengths together
	// returns a Length struct

	Length tot;

	tot.m = l1.m + l2.m;
	tot.cm = l1.cm +l2.cm;

	if (tot.cm >= 100) {
		tot.m += tot.cm / 100;
		tot.cm -= 100;
		/* something is wrong with this, but I'm not sure what
		 * I gave it the two numbers, 4.40 and 4.65. The procedure about this
		 * if statement gives the answer of 8.105. This is fine - 8 meters
		 * and 105 cm. The 1 should be shifted over to the left side, making it
		 * 9 meters, and the 05 should stay to the right. The correct answer
		 * should be 9.05. Instead, I get 9.5.
		 * when I put 4.45 in instead of 4.40, it works correctly and gives the
		 * answer 9.10. 
		 */
	}
	
	return tot;
}

Length sub(Length l1, Length l2) {
	// subtract l2 from l1
	// returns a Length struct

	Length tot;

	tot.m = l1.m - l2.m;
	tot.cm = l1.cm - l2.cm;

	return tot;
}

int main(void) {

	// length 1
	Length l1;
	l1.m = 3;
	l1.cm = 05;

	// length 2
	Length l2;
	l2.m = 10;
	l2.cm = 0;

	Length a = add(l1, l2);
	Length s = sub(l1, l2);
	printf("%d.%d + %d.%d = %d.%d\n", l1.m, l1.cm, l2.m, l2.cm, a.m, a.cm);
	printf("%d.%d - %d.%d = %d.%d\n", l1.m, l1.cm, l2.m, l2.cm, s.m, s.cm);

	return 0;
}
