/* 
		file: task2.c
		author: Brendon Walter
		date: 2014 November 24

		AVL Tree Lab task #2
 */

#include <stdio.h>
#include "tree.h"

/* Parameters: Pointer to root of a tree
 * Returns: balance factor in terms of an int
 * Gets the balance factor of a tree and then returns it.
 */
int getBalanceFactor(TreeNode* root) {
	int balanceFactor = 0;
	if (root != NULL) 
		balanceFactor = getHeight(root->left) - getHeight(root->right);
	
	return balanceFactor;
}

int main(void) {
    BinaryTree bt;
    bt.root = NULL;
    NodeData d;
 
    int i=0;
    while (i<5) {
        printf("Enter a node value: ");
        scanf("%s", d.val);
		findOrInsert(&bt, d);
        i++;
    } 
	printf("%d\n", getBalanceFactor(bt.root));
}

