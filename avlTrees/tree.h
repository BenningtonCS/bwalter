/* file: tree.h
 * date: 2014 November 4
 * author: Brendon Walter
 *
 * Basic implementation of a binary tree
 * 	Now includes binary search tree functionality!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 65

// allows for data of any type to be put into the tree
typedef struct {
	char val[BUF];
} NodeData;

// struct for each node in the tree
typedef struct treenode {
	NodeData data;
	int balance;
	struct treenode *left, *right, *parent;	// left / right children
} TreeNode;

// struct for the whole tree
typedef struct binarytree {
	TreeNode *root;
} BinaryTree;

void visit(TreeNode* node);

// visit root, pre-order left, pre-order right
void preOrder(TreeNode* node);

// post-order left, post-order right, visit root
void postOrder(TreeNode* node);

// in-order left, visit root, in-order right
void inOrder(TreeNode* node);

// gets the height of a tree
int getHeight(TreeNode* root);

// builds a binary tree from a file (tree.txt)
TreeNode* buildTree(FILE *in);

/* Paramters: Data to add to node
 * Returns: Pointer to newly created node
 * Creates and adds a new node to the binary search tree
 */
TreeNode* newTreeNode(NodeData d, TreeNode* pparent); 

/* Parameters: Pointer to root of a binary search tree, data to add
 * Returns: Pointer to the found/created node
 * Searches a binary search tree for a node and returns it if found. If the
 * Node doesn't exist, make a new one and return a pointer to it.
 */ 
TreeNode* findOrInsert(BinaryTree *bt, NodeData d);

TreeNode* find(BinaryTree bt, NodeData d, TreeNode** pparent, int* isLeft, TreeNode** unbalanced);

TreeNode* insert(BinaryTree bt, NodeData d); 
