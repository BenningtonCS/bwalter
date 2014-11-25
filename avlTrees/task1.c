/* 
		file: task1.c
		author: Brendon Walter
		date: 2014 November 24

		AVL Tree Lab task #1
 */

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

#define WORDS 99171		// words in /usr/share/dict/words

int main(void) {
	char buf[BUF];
	char* fileName = "/usr/share/dict/words";
    FILE *in = fopen(fileName, "r");

	BinaryTree bt; 
	bt.root = NULL;
	NodeData d;

	int i;
	for (i=0;i<WORDS;i++) {
		fscanf(in, "%s", buf);
		strcpy(d.val, buf);
		findOrInsert(&bt, d);
	}

	preOrder(bt.root);
	printf("%d\n", getHeight(bt.root));
}
