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

/* Parameters: BT to search, node to find
 *		Output: parent of found pointer, int indicating position of node
 * Returns: NULL if the node isn't found
 */
TreeNode* find(BinaryTree bt, NodeData d, TreeNode** pparent, int* isLeft, TreeNode** unbalanced) {
	TreeNode* curr = bt.root;
	int cmp;
    
    // check for empty tree
    if (curr == NULL) 
        //return bt.root = newTreeNode(d, *pparent);
		return NULL;
     
    while ((cmp = strcmp(d.val, curr->data.val)) != 0) {
		if (cmp<0) {					// try left
			if (curr->balance != 0) *unbalanced = curr;
            if (curr->left == NULL) {
				*pparent = curr;		// set parent
				*isLeft = 1;			// node found on the left
				return NULL;
			}
            curr = curr->left;  
        } else {						// try right
			if (curr->balance != 0) *unbalanced = curr;
			if (curr->right == NULL) {
				*pparent = curr;		// set parent
				*isLeft = 0;			// node found on the right
				return NULL;
			}
            curr = curr->right; 
         }   
    } 
	return curr; 
}

TreeNode* insert(BinaryTree bt, NodeData d) {
	TreeNode *pparent = NULL;		// set values
	TreeNode *unbalanced;
	int isLeft = -1;	
	
	// find the parent and position of the node in the tree
	TreeNode* key = find(bt, d, &pparent, &isLeft, &unbalanced);
	if (key != NULL) return key;

	else {	
	// create the new node
	key = newTreeNode(d, pparent);
	if (pparent == NULL) return bt.root = key;
	printf("%p: %d\n", key->parent, key->data.val);
	pparent = key->parent;

	if (isLeft) key->parent->left = key;
	else key->parent->right = key;
	
	for (;;) {	
		if (pparent->left == key) pparent->balance--;
		else pparent->balance++;
		if (pparent == unbalanced) break;
		key = pparent;
		pparent = pparent->parent;
	}
	}
}

int main(void) {
    BinaryTree bt;
    bt.root = NULL;
    NodeData d;

/* 
    printf("Enter a node value: ");
    scanf("%s", d.val);
	bt.root = insert(bt, d);
*/  
    int i=0;
	while (i<5) {
        printf("Enter a node value: ");
        scanf("%s", d.val);
		bt.root = insert(bt, d);
        i++;
    } 

	printf("%p\n", bt.root);
	preOrder(bt.root);	
}

