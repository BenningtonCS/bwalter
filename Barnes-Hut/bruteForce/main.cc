#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <X11/Xlib.h>
#include <unistd.h>

#include "Body.h"
#include "Universe.h"

using namespace std;

#define NUM_BODIES 1000	// number of particles in simulation
#define UNIVERSE 750 
#define TIME_STEP 1000


int main(void) {

	srand(time(NULL));		// make it possible to generate random numbers

	// S E T U P   U N I V E R S E

	Universe uni;
	uni.setSize(UNIVERSE); 	
	
	Body b[NUM_BODIES];
	b[0].makeBody(1E36, uni.getCenter().x, uni.getCenter().y, 0, 0);
	

	int i;
	for (i=1;i<NUM_BODIES;i++) 
		b[i].makeRandomBody(uni.getSize()* 3/8, uni.getSize() * 5/8); 

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
	
	
		int i, j;
		for (i=1;i<NUM_BODIES;i++) {
			b[i].resetForce();
			for (j=1;j<NUM_BODIES;j++) { 
				if (i != j) b[i].calcForce(b[j]);
			}
		}

		XClearWindow(dis, win);		// clear the window
		for (i=0;i<NUM_BODIES;i++)	{
			b[i].update(TIME_STEP);
			XDrawPoint(dis, win, gc, b[i].pos.x, b[i].pos.y); 
		}		
		
		XFlush(dis);				// send draw point requests to server
		
		usleep(100);		
	}
}
