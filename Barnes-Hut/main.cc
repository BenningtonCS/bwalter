#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <X11/Xlib.h>
#include <unistd.h>

#include "Body.h"
#include "Universe.h"

using namespace std;

const int NUM_BODIES = 100;	// number of particles in simulation

int main(void) {

	srand(time(NULL));		// make it possible to generate random numbers
	
	Body b[NUM_BODIES];				// create each body
	b[0].makeBody(100, 0, 0, 0, 0);	// make large body in center
	
	int i;
	for (i=1;i<NUM_BODIES;i++) 
		b[i].makeRandomBody(500);
	

	// S E T U P   X
	
	Display *dis = XOpenDisplay(NULL);
	if (dis == NULL) exit(1);

	int black = BlackPixel(dis, DefaultScreen(dis));
	int white = WhitePixel(dis, DefaultScreen(dis));
	
	// create window
	Window win = XCreateSimpleWindow(dis, DefaultRootWindow(dis), 0, 0, 500, 500, 0, black, black);
	
	XSelectInput(dis, win, StructureNotifyMask);// want to get MapNotify events
	XMapWindow(dis, win);					// map the window
	GC gc = XCreateGC(dis, win, 0, NULL);	// create graphics context
	XSetForeground(dis, gc, white);			// tell gc that we draw using white

	XEvent e;
	while (e.type != MapNotify)				// wait for MapNotify event
		XNextEvent(dis, &e);

	for(i=0;i<NUM_BODIES;i++) {
		XDrawPoint(dis, win, gc, b[i].pos.x, b[i].pos.y); 
	}

	XFlush(dis);

	sleep(10);
}
