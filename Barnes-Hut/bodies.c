/*
	bodies.c
	2014 December 5
	Brendon Walter

	Data Structures in C final project
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUF 65
#define TOT_BODIES 10
#define X 0
#define Y 1

typedef struct {
	double totalMass;
	double mass;
	double r[2];	// position
	double v[2];	// velocity
} Body;

typedef struct treenode{
	Body data;
	struct treenode *nw, *ne, *sw, *se;
} TreeNode;

typedef struct quadtree {
	TreeNode *root;
} QuadTree;

TreeNode* newTreeNode(double mass, double r[], double v[]) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	if (p == NULL)  exit(1);
	p->data.totalMass = -1;
	p->data.mass = mass;
	p->data.r[X] = r[X];
	p->data.r[Y] = r[Y];
	p->data.v[X] = v[X];
	p->data.v[Y] = v[Y];
	p->nw = p->ne = p->sw = p->se = NULL;
	return p;
}

int randomNum(int end) {
	return rand() % end + (-end/2);
}

void createTree(QuadTree *qt, Body bodies[]) {
	int i;
	for (i=0;i<TOT_BODIES;i++) {
		bodies[i].mass = 1;
		bodies[i].r[X] = randomNum(10);
		bodies[i].r[Y] = randomNum(10);
		bodies[i].v[X] = randomNum(10);
		bodies[i].v[Y] = randomNum(10);	
	}

	if (qt->root == NULL) qt->root = bodies[0];
}

int main(void) {
	srand(time(NULL));

	QuadTree qt;
	qt.root = NULL;


	Body bodies[TOT_BODIES];


}
