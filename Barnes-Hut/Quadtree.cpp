/*
	Quadtree.cpp
	2014 December 8
	Brendon Walter

	Methods for everything to do with Quadtrees
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <new>

#include "Quadtree.h"

#define UNIVERSE 750 
#define THETA 0.5

using namespace std;

void QuadTree::calcForce(TreeNode node, Body b) {
	// if current node is an external node (and is not b)
	if (node.external && node.body != b) b.calcForce(node.body);
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
	p->external = 1;
	p->size.x = p->size.y = 0;
	p->center.x = p->center.y = 0;
	p->mass = 0;		
	p->nw = p->ne = p->sw = NULL;
	p->se = NULL;

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
		if (b.pos.y >= center.y) return 4;
		else return 1;
	} else {
		if (b.pos.y >= center.y) return 3;
		else return 2;
	}
}

/*
	Parameters: Old center of mass, Body node of root of tree, 
			new body to be added to tree
	Returns: Point to the new center of gravity
	Adds a new star to a cluster and calculates the new center of mass
*/
Point findMassCenter(Point center, double mass, Body b) {
	Point p;
	double m = mass + b.mass;
	p.x = ((center.x * mass) + (b.pos.x * b.mass)) / m;
	p.y = ((center.y * mass) + (b.pos.y * b.mass)) / m;
	return p;
}

/*
	Parameters: Pointer to a treenode, body to be inserted, center of quadrant
	Returns: A pointer to the newly created node
	Each of the following functions insert a new node into the NE, NW, SE, or
		SW quadrants
*/

TreeNode* NEinsert(TreeNode* node, Body b, Point center) {
	cout << "in ne insert" <<endl;
	cout << node->ne <<endl;
	TreeNode* curr = node->ne;

	if (node->ne == NULL) {			// Node does not contain a body
		node->ne = newNode(b);
	} else if (!curr->external) 	// node is internal
		NEinsert(curr, b, center);
	else {						// node is external
		// sub divide region
		center.x *= 1.5;
		center.y *= 0.5;

		// re-insert body that was already in this node
		int q = findQuadrant(center, curr->body);
		if (q == 1) NEinsert(node, curr->body, center);
		if (q == 2) NWinsert(node, curr->body, center);
		if (q == 3) SEinsert(node, curr->body, center);
		if (q == 4) SWinsert(node, curr->body, center);

		// node becomes an internal node
		curr->external = 0;
		// insert new body
		NEinsert(node, b, center);
	}

	curr = node->ne;
	curr->center = findMassCenter(curr->center, curr->mass, b);
	curr->body.mass += b.mass;
	cout << "done with ne insert" <<endl;
}

TreeNode* NWinsert(TreeNode* node, Body b, Point center) {
	cout << "in nw insert" <<endl;
	cout << node->nw <<endl;
	TreeNode* curr = node->nw;

	if (node->nw == NULL) {			// Node does not contain a body
		node->nw = newNode(b);
	} else if (!curr->external) 	// node is internal
		NWinsert(curr, b, center);
	else {						// node is external
		// sub divide region
		center.x *= 0.5;
		center.y *= 0.5;

		// re-insert body that was already in this node
		int q = findQuadrant(center, curr->body);
		if (q == 1) NEinsert(node, curr->body, center);
		if (q == 2) NWinsert(node, curr->body, center);
		if (q == 3) SEinsert(node, curr->body, center);
		if (q == 4) SWinsert(node, curr->body, center);

		// node becomes an internal node
		curr->external = 0;
		// insert new body
		NWinsert(node, b, center);
	}

	curr = node->nw;
	curr->center = findMassCenter(curr->center, curr->mass, b);
	curr->body.mass += b.mass;
	cout << "done with nw insert" <<endl;
}

TreeNode* SEinsert(TreeNode* node, Body b, Point center) {
	cout << "in se insert" <<endl;
	cout << node->se <<endl;
	TreeNode* curr = node->se;

	if (node->se == NULL) {			// Node does not contain a body
		node->se = newNode(b);
	} else if (!curr->external) 	// node is internal
		SEinsert(curr, b, center);
	else {						// node is external
		// sub divide region
		center.x *= 1.5;
		center.y *= 1.5;

		// re-insert body that was already in this node
		int q = findQuadrant(center, curr->body);
		if (q == 1) NEinsert(node, curr->body, center);
		if (q == 2) NWinsert(node, curr->body, center);
		if (q == 3) SEinsert(node, curr->body, center);
		if (q == 4) SWinsert(node, curr->body, center);

		// node becomes an internal node
		curr->external = 0;
		// insert new body
		SEinsert(node, b, center);
	}

	curr = node->se;
	curr->center = findMassCenter(curr->center, curr->mass, b);
	curr->body.mass += b.mass;

	cout << "done with se insert" <<endl;
}

TreeNode* SWinsert(TreeNode* node, Body b, Point center) {
	cout << "in sw insert" <<endl;
	cout << node->sw <<endl;
	TreeNode* curr = node->sw;

	if (node->sw == NULL) {			// Node does not contain a body
		node->sw = newNode(b);
	} else if (!curr->external) 	// node is internal
		SWinsert(curr, b, center);
	else {						// node is external
		// sub divide region
		center.x *= 0.5;
		center.y *= 1.5;

		// re-insert body that was already in this node
		int q = findQuadrant(center, curr->body);
		if (q == 1) NEinsert(node, curr->body, center);
		if (q == 2) NWinsert(node, curr->body, center);
		if (q == 3) SEinsert(node, curr->body, center);
		if (q == 4) SWinsert(node, curr->body, center);

		// node becomes an internal node
		curr->external = 0;
		// insert new body
		SWinsert(node, b, center);
	}

	curr = node->sw;
	curr->center = findMassCenter(curr->center, curr->mass, b);
	curr->body.mass += b.mass;
	cout << "done with sw insert" <<endl;
}

/*
	Parameters: Universe the body resides in, the tree to put it into, and the 
		body itself to be inserted
	Returns: Pointer to newly created node in the tree
	Inserts a new node into the quadtree that contains the body
*/
TreeNode* insertNode(Universe uni, QuadTree* qt, Body b) {
	if (qt->root == NULL) {
		Body empty;
		empty.makeEmptyBody();
		qt->root = newNode(empty);
	}

	TreeNode* curr = qt->root;
	int q = findQuadrant(uni.getCenter(), b);
	
	if (q == 1) NEinsert(curr, b, uni.getCenter());
	if (q == 2) NWinsert(curr, b, uni.getCenter());
	if (q == 3) SEinsert(curr, b, uni.getCenter());
	if (q == 4) SWinsert(curr, b, uni.getCenter());
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
