/* file: 18.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 18: "Write a function that will read one line of input from
 * the terminal. The input is supposed to consist of two parts, seperated by a
 * colon..."
 */

#include <stdio.h>
#include <stdlib.h>

/* Paramterers: None
 * Returns: N if no colon in the line, L if the left part is larger, R if right,
 * D if both sides are the same size but have different content, S if both sides
 * are the same.
 * Checks a string from user input and returns the results
 */
char readInput() {
	
	// get string from user
	char str[256];
	printf("Enter something:\n");
	scanf("%79[^\n]%*c", str);		// ugliness from stackoverflow (for spaces)

	// i: counter
	// key: 0 for left side of colon, flipped to 1 for being on the right
	// left: counter for letters left of colon
	// right: counter for letters right of colon
	int i, key, left, right;
	i = key = left = right = 0;

	while (str[i] != '\0') {	// walk through entire string
		if (key == 0) left++;	// if the key is 0, increase count for left
		if (key == 1) right++;	// if the key is 1, increase count for right
		if (str[i] == ':') {	// if the current character is the colon
			key = 1;			// flip the key
			left--;				// and decrease left which was already increased
		}
		str[i];
		i++;
	}

	// return values based on above results
	if (key == 0) return 'N';
	if (left > right) return 'L';
	if (left < right) return 'R';

	// if the sides are the same size
	if (left == right) {
		char r[right], l[left];		// create vectors to hold the letters
		
		i = key = 0;
		for (i=0;i<left;i++) {		// walk through half the list
			l[i] = str[i];			// add values to the left array
			r[i] = str[left+1+i];	// and add the values passed : to the right
		}
		
		for (i=0;i<right;i++) {		// check contents of each array
			if (r[i] != l[i]) return 'D';	// if they differ return D
		}	
		return 'S';					// otherwise, they are the same
	}

	return '?';			// I really don't know what you did to get here.

}

int main(void) {	
	char n = readInput();
	printf("%c\n", n);
}
