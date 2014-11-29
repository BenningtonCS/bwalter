/* file: bst.c
 * date: 2014 November 4
 * author: Brendon Walter
 *
 * Basic implementation of a binary tree
 *	Now includes binary search tree functionality!
 */

#include "tree.h"
#define MAX ( ( a, b ) ( ( a > b) ? a : b ) 
inline int max ( int a, int b ) { return a > b ? a : b; }

void visit(TreeNode* node) {
	printf("%s\t%d\n", node->data.val, node->balance);
}

// visit root, pre-order left, pre-order right
void preOrder(TreeNode* node) {
	if (node != NULL) {
		visit(node);				// visit current node
		preOrder(node->left);		// recursively call preOrder and go left
		preOrder(node->right);		// recursively call preOrder and go right
	}
}

// post-order left, post-order right, visit root
void postOrder(TreeNode* node) {
	if (node != NULL) {
		postOrder(node->left);		// recursively call prostOrder and go left
		postOrder(node->right);		// recursively call postOrder and go right
		visit(node);				// visit current node
	}
}

// in-order left, visit root, in-order right
void inOrder(TreeNode* node) {
	if (node != NULL) {
		inOrder(node->left);		// recursively call inOrder and go left
		visit(node);					// visit current node
		inOrder(node->right);		// recursively call inOrder and go right
	}
}


// gets the height of a tree
int getHeight(TreeNode* root) {
	if (root == NULL) return 0;
	return 1 + max(getHeight(root->left), getHeight(root->right));
}

// builds a binary tree from a file (tree.txt)
TreeNode* buildTree(FILE *in) {
	char buf[BUF];
	fscanf(in, "%s", buf);
	if (strcmp(buf, "@") == 0) return NULL;	// if @ is first and only character
	TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
	if (p == NULL) exit(1);
	strcpy(p->data.val, buf);		// copy buf into the tree node value
	p->left = buildTree(in);
	p->right = buildTree(in);
	return p;
}

/* Paramters: Data to add to node, parent of new node
 * Returns: Pointer to newly created node
 * Creates and adds a new node to the binary search tree
 */
TreeNode* newTreeNode(NodeData d, TreeNode* pparent) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	if (p == NULL) exit (1);
	p->data = d;
	p->balance = 0;
	p->left = p->right = NULL;
	p->parent = pparent;
	return p;
}

/* Parameters: Pointer to root of a binary search tree, data to add
 * Returns: Pointer to the found/created node
 * Searches a binary search tree for a node and returns it if found. If the
 * Node doesn't exist, make a new one and return a pointer to it.
 */ 
TreeNode* findOrInsert(BinaryTree *bt, NodeData d) {
	TreeNode* curr = bt->root;
	int cmp;

	// check for empty tree
	if (bt->root == NULL) {
		return bt->root = newTreeNode(d, bt->root);
	}

	while ((cmp = strcmp(d.val, curr->data.val)) != 0) {
	//while (d.val == curr->data.val != 0) {
		if (cmp<0) {	// try left
			if (curr->left == NULL) return curr->left = newTreeNode(d, curr);
			curr = curr->left;	
		} else {		// try right
			if (curr->right == NULL) return curr->right = newTreeNode(d, curr);
			curr = curr->right;	
		}
	}
}
