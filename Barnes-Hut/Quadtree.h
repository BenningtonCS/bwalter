/*
	Quadtree.h
	2014 December 8
	Brendon Walter

	Quadtree struct to hold each body in the simulation
*/

#ifndef QUADTREE_H
#define QUADTREE_H

#include "Body.h"

struct TreeNode {
	Body body;			// body to be placed in tree
	double mass;		// total mass in each node
	Point center;		// center of mass
	TreeNode *nw, *ne, *sw, *se;	// sub trees
};

struct QuadTree {
	TreeNode *root;
};

#endif
