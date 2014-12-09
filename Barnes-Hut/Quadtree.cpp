/*
	Quadtree.cpp
	2014 December 8
	Brendon Walter

	Methods for everything to do with Quadtrees
*/

#include <cstdlib>
#include <new>

#include "Quadtree.h"

/*
	Parameters: Body to be inserted into tree
	Returns: Pointer to the created node
	Creates a new node in the tree that contains input body
*/
TreeNode* newNode(Body b) {
	TreeNode* p = new (std::nothrow) TreeNode;
	if (p == 0) exit(1);

	p->body = b;	// set body
	p->mass = 0;	// set total mass of node to 0
	p->nw = p->ne = p->sw = p->se = NULL;

	return p;
}

/*
	Parameters: Point of center of the universe, body to find quadrant of
	Returns: int indicating which quadrant
	Returns an integer indicating what quadrant the body is found in
	1 = NE	|	2 = NW	|	3 = SW	|	4 = SE
*/
int findQuadrant(Point center, Body b) {
	if (b.pos.x >= center.x) {
		if (b.pos.y >= center.y) return 1;
		else return 4;
	} else {
		if (b.pos.y >= center.y) return 2;
		else return 3;
	}
}

TreeNode* NEinsert(TreeNode* node, Body b, Point center) {

}

TreeNode* NWinsert(TreeNode* node, Body b, Point center) {
	TreeNode* curr = node->nw;
	int quad;	

	while (curr->mass > 0) {	// there is already a node
		center.x /= 2;
		center.y /= 2;
		curr->nw = curr;
		
		quad = findQuadrant(center, b);
		if (quad == 1) NEinsert(curr, b, center);
		if (quad == 2) NWinsert(curr, b, center);
		if (quad == 3) SWinsert(curr, b, center);
		if (quad == 4) SEinsert(curr, b, center);
	}
	
	curr->body = b;
	curr->mass += b.mass;
}

TreeNode* SEinsert(TreeNode* node, Body b, Point center) {

}

TreeNode* SWinsert(TreeNode* node, Body b, Point center) {

}

/*
	Parameters: Universe the body resides in, the tree to put it into, and the 
		body itself to be inserted
	Returns: Pointer to newly created node in the tree
	Inserts a new node into the quadtree that contains the body
*/
TreeNode* insertNode(Universe uni, QuadTree* qt, Body b) {
	int i;
	TreeNode* curr = qt->root;

	// check if tree is empty
	if (qt->root == NULL) {
		Body root;					// create root body
		qt->root = newNode(root);
		return qt->root;
	}
	
	// figure out what quadrant the body is in
	Point center = uni.getCenter();
	int quad = findQuadrant(center, b);

	if (quad == 1)				// NORTH EAST QUADRANT
		NEinsert(curr, b, center);

	else if (quad == 2)			// NORTH WEST QUADRANT
		NWinsert(curr, b, center);

	else if (quad == 3)			// SOUTH WEST QAUDRANT
		SWinsert(curr, b, center);

	else if (quad == 4)			// SOUTH EAST QUADRANT
		SEinsert(curr, b, center);

	// update mass of root
	qt->root->mass += b.mass;

	return curr;
}
