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

char readInput() {
	
	char str[256];
	printf("Enter something:\n");
	scanf("%79[^\n]%*c", str);		// ugliness from stackoverflow

	int i, key, left, right;
	i = key = left = right = 0;

	while (str[i] != '\0') {
		if (key == 0) left++;
		if (key == 1) right++;
		if (str[i] == ':') {
			key = 1;
			left--;
		}
		str[i];
		i++;
	}


	if (key == 0) return 'N';
	if (left > right) return 'L';
	if (left < right) return 'R';

	if (left == right) {
		char r[right], l[left];
		
		i = key = 0;
		while (str[i] != '\0') {
			if (key == 0) l[i] = str[i];
			if (key == 1) r[i] = str[i];
			if (str[i] == ':') key = 1;
			printf("l[%d]: %c\nr[%d]: %c\n", i, l[i], i, r[i]);
			str[i];
			i++;
		}

		
		for (i=0;i<right;i++) {
			if (r[i] != l[i]) return 'D';
		}	
		return 'S';
	}

	return '?';

}

int main(void) {	
	char n = readInput();
	printf("%c\n", n);
}
