/*
	main.cc
	2014 December 5
	Brendon Walter

	Data Structures in C final project

	N-body simulation in 2d using the Barnes-Hut algorithm
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <X11/Xlib.h>
#include <unistd.h>

#include "Body.h"
#include "Universe.h"
#include "Quadtree.h"

using namespace std;

#define NUM_BODIES 100	// number of particles in simulation
#define UNIVERSE 750 
#define TIME_STEP 10000 
#define THETA 0.5

int main(void) {

	srand(time(NULL));		// make it possible to generate random numbers

	// S E T U P   U N I V E R S E

	Universe uni;
	uni.setSize(UNIVERSE); 	
	
	Body b[NUM_BODIES];

	int i;
	for (i=0;i<NUM_BODIES;i++) 
		b[i].makeRandomBody(uni.getSize()* 3/8, uni.getSize() * 5/8); 

	QuadTree qt;

	// S E T U P   X
	
	Display *dis = XOpenDisplay(NULL);
	if (dis == NULL) exit(1);

	int black = BlackPixel(dis, DefaultScreen(dis));
	int white = WhitePixel(dis, DefaultScreen(dis));
	
	// create window
	Window win = XCreateSimpleWindow(dis, DefaultRootWindow(dis), 0, 0, UNIVERSE, UNIVERSE, 0, black, black);
	
	XSelectInput(dis, win, StructureNotifyMask);// want to get MapNotify events
	XMapWindow(dis, win);					// map the window
	GC gc = XCreateGC(dis, win, 0, NULL);	// create graphics context
	XSetForeground(dis, gc, white);			// tell gc that we draw using white

	XEvent e;
	while (e.type != MapNotify)				// wait for MapNotify event
		XNextEvent(dis, &e);


	// S T A R T   T I M E

	while(1) {

		qt.root = NULL;
	
		int i;
		for (i=0;i<NUM_BODIES;i++) 
			insertNode(uni, &qt, b[i]);

		
		for (i=0;i<NUM_BODIES;i++) 
			b[i].resetForce();
		

		XClearWindow(dis, win);		// clear the window


		for (i=0;i<NUM_BODIES;i++) 
			qt.calcForce(*(qt.root), b[i]);
		
		// update each particle and draw it to the screen
		for (i=0;i<NUM_BODIES;i++)	{
			b[i].update(TIME_STEP);
			XDrawPoint(dis, win, gc, b[i].pos.x, b[i].pos.y); 
		}		
		
		deleteTree(qt.root);
		
		XFlush(dis);	// send draw point requests to server
		usleep(100);	// keep program from over loading computer	

	}
}
