/*
	Quadtree.cpp
	2014 December 8
	Brendon Walter

	Methods for everything to do with Quadtrees
*/

#include <cmath>
#include <cstdlib>
#include <new>

#include "Quadtree.h"

#define UNIVERSE 750 
#define THETA 0.5

void QuadTree::calcForce(TreeNode node, Body b) {
	// if current node is an external node (and is not b)
	if (node.external) b.calcForce(node.body);
	// otherwise calculate the radio s/d
	else {
		double s = node.size.x;
		double d = sqrt(pow(node.body.pos.x - b.pos.x, 2) + 
						pow(node.body.pos.y - b.pos.y, 2));

		double ratio = s/d;

		// if the ratio is greater than theta, use internal node as a single
		// body, and calculate the force it exerts on body b, and add this 
		// amount to b's net force
		if (ratio > THETA) b.calcForce(node.body);

		// otherwise, run the procedure recursively on each of the current 
		// node's children
		else {
			calcForce(*(node.ne), b); 
			calcForce(*(node.nw), b); 
			calcForce(*(node.se), b); 
			calcForce(*(node.sw), b); 
		}
	}	
}

/*
	Parameters: Body to be inserted into tree
	Returns: Pointer to the created node
	Creates a new node in the tree that contains input body
*/
TreeNode* newNode(Body b) {
	TreeNode* p = new (std::nothrow) TreeNode;
	if (p == 0) exit(1);

	p->body = b;	// set body
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

/*
	Parameters: Body node of root of tree, new body to be added to tree
	Returns: Point to the new center of gravity
	Adds a new star to a cluster and calculates the new center of mass
*/
Point findMassCenter(Body m1, Body m2) {
	Point p;
	double m = m1.mass + m2.mass;
	p.x = ((m1.pos.x * m1.mass) + (m2.pos.x * m2.mass)) / m;
	p.y = ((m1.pos.y * m1.mass) + (m2.pos.y * m2.mass)) / m;
	return p;
}

/*
	Parameters: Pointer to a treenode, body to be inserted, center of quadrant
	Returns: A pointer to the newly created node
	Each of the following functions insert a new node into the NE, NW, SE, or
		SW quadrants
*/

TreeNode* NEinsert(TreeNode* node, Body b, Point center) {
    TreeNode* curr = newNode(b);
	node->ne = curr;
	int quad;

	if (curr->body.mass > 0) {	// there is already a node
		center.x *= 1.5;
		center.y *= 0.5;

		curr->ne = curr;
		quad = findQuadrant(center, b);
		if (quad == 1) NEinsert(curr, b, center);
		if (quad == 2) NWinsert(curr, b, center);
		if (quad == 3) SWinsert(curr, b, center);
		if (quad == 4) SEinsert(curr, b, center);
	}

	Body empty;
	empty.makeEmptyBody();
	node->body = empty;
	node->body.mass += b.mass;
	node->body.pos = findMassCenter(node->body, b);
	curr->body = b;
	curr->body.mass += b.mass;
	curr->size.x = center.x / 2;
	curr->size.y = center.y / 2;
	
	return curr;
}

TreeNode* NWinsert(TreeNode* node, Body b, Point center) {
    TreeNode* curr = newNode(b);
	node->nw = curr;
	int quad;	

	if (curr->body.mass > 0) {	// there is already a node
		center.x *= 0.5;
		center.y *= 0.5;
		curr->nw = curr;
		
		quad = findQuadrant(center, b);
		if (quad == 1) NEinsert(curr, b, center);
		if (quad == 2) NWinsert(curr, b, center);
		if (quad == 3) SWinsert(curr, b, center);
		if (quad == 4) SEinsert(curr, b, center);
	}

	Body empty;
	empty.makeEmptyBody();
	node->body = empty;
	node->body.mass += b.mass;
	node->body.pos = findMassCenter(node->body, b);
	curr->body = b;
	curr->body.mass += b.mass;
	curr->size.x = center.x / 2;
	curr->size.y = center.y / 2;
	return curr;
}

TreeNode* SEinsert(TreeNode* node, Body b, Point center) {
	TreeNode* curr = newNode(b);
	node->se = curr;
    int quad;

    if (curr->body.mass > 0) {   // there is already a node
        center.x *= 1.5;
        center.y *= 1.5;

        curr->se = curr;
        quad = findQuadrant(center, b);
        if (quad == 1) NEinsert(curr, b, center);
        if (quad == 2) NWinsert(curr, b, center);
        if (quad == 3) SWinsert(curr, b, center);
        if (quad == 4) SEinsert(curr, b, center);
    }

	Body empty;
	empty.makeEmptyBody();
	node->body = empty;
	node->body.mass += b.mass;
	node->body.pos = findMassCenter(node->body, b);
	curr->body = b;
	curr->body.mass += b.mass;
	curr->size.x = center.x / 2;
	curr->size.y = center.y / 2;
	return curr;
}

TreeNode* SWinsert(TreeNode* node, Body b, Point center) {
	TreeNode* curr = newNode(b);
	node->sw = curr;
    int quad;

    if (curr->body.mass > 0) {   // there is already a node
        center.x *= 0.5;
        center.y *= 1.5;

        curr->sw = curr;
        quad = findQuadrant(center, b);
        if (quad == 1) NEinsert(curr, b, center);
        if (quad == 2) NWinsert(curr, b, center);
        if (quad == 3) SWinsert(curr, b, center);
        if (quad == 4) SEinsert(curr, b, center);
    }

	Body empty;
	empty.makeEmptyBody();
	node->body = empty;
	node->body.mass += b.mass;
	node->body.pos = findMassCenter(node->body, b);
	curr->body = b;
	curr->body.mass += b.mass;
	curr->size.x = center.x / 2;
	curr->size.y = center.y / 2;
	return curr;
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
		curr->ne = NEinsert(curr, b, center);

	else if (quad == 2)			// NORTH WEST QUADRANT
		curr->nw = NWinsert(curr, b, center);

	else if (quad == 3)			// SOUTH WEST QAUDRANT
		curr->sw = SWinsert(curr, b, center);

	else if (quad == 4)			// SOUTH EAST QUADRANT
		curr->se = SEinsert(curr, b, center);

	// update mass of root
	qt->root->body.mass += b.mass;

	return curr;
}

/*
	Parameters: Pointer to root of tree node
	Returns: None
	Recursively travel through the entire tree and delete every node
*/
void deleteTree(TreeNode* root) {
	if (root->ne != NULL) deleteTree(root->ne);
	if (root->nw != NULL) deleteTree(root->nw);
	if (root->se != NULL) deleteTree(root->se);
	if (root->sw != NULL) deleteTree(root->sw);
	else delete root;
}
