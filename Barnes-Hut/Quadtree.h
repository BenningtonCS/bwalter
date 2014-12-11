/*
	Quadtree.h
	2014 December 8
	Brendon Walter

	Quadtree struct to hold each body in the simulation
*/

#ifndef QUADTREE_H
#define QUADTREE_H

#include "Universe.h"
#include "Body.h"

struct TreeNode {
	Body body;			// body to be placed in tree
	int external;		// 1 if it's external, 0 if it's an internal node
	Point size;			// side lengths of the quad the node represents
	Point center;		// center of mass
	double mass;		// total mass of node and all child nodes
	TreeNode *nw, *ne, *sw, *se;	// sub trees
};

struct QuadTree {
	TreeNode *root;

	void calcForce(TreeNode node, Body b);
};

/*
	Parameters: Body to be inserted into tree
	Returns: Pointer to the created node
	Creates a new node in the tree that contains input body
*/
TreeNode* newNode(Body b);

/*
	Parameters: Point of center of the universe, body to find quadrant of
	Returns: int indicating which quadrant
	Returns an integer indicating what quadrant the body is found in
	1 = NE	|	2 = NW	|	3 = SW	|	4 = SE
*/
int findQuadrant(Point center, Body b); 

/*
	Parameters: Old center of mass, Body node of root of tree, 
			new body to be added to tree
	Returns: Point to the new center of gravity
	Adds a new star to a cluster and calculates the new center of mass
*/
Point findMassCenter(Point center, double mass, Body b); 

/*
	Parameters: Pointer to a treenode, body to be inserted, center of quadrant
	Returns: A pointer to the newly created node
	Each of the following functions insert a new node into the NE, NW, SE, or
		SW quadrants
*/
TreeNode* NEinsert(TreeNode* node, Body b, Point center);
TreeNode* NWinsert(TreeNode* node, Body b, Point center);
TreeNode* SEinsert(TreeNode* node, Body b, Point center);
TreeNode* SWinsert(TreeNode* node, Body b, Point center);

/*
	Parameters: Universe the body resides in, the tree to put it into, and the 
		body itself to be inserted
	Returns: Pointer to newly created node in the tree
	Inserts a new node into the quadtree that contains the body
*/
TreeNode* insertNode(Universe uni, QuadTree* qt, Body b); 

/*
	Parameters: Pointer to root of tree node
	Returns: None
	Recursively travel through the entire tree and delete every node
*/
void deleteTree(TreeNode* root);

#endif
