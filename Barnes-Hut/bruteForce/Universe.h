/*
	Universe.h
	2014 December 5
	Brendon Walter

	struct for x, y coordinates; class for the universe
*/

#ifndef UNIVERSE_H
#define UNIVERSE_H

// x and y values for positions and vectors (velocity, force, acceleration)
struct Point {
	double x;
	double y;
};

class Universe {

	private:
		Point center;			// coordinates for the center of the universe
		int size;				// size of the universe in pixels 
		Point halfDimension;	// half the side length of the universe

	public:
		
		// set the size (in pixels) for the universe and calculates the center
		void setSize(int pixels) {
			size = pixels;
			center.x = center.y = pixels / 2;
		}

		// return the size of the universe
		int getSize() {
			return size;
		}

		// returns the x,y coordinates for the center of the universe
		Point getCenter() {
			return center;
		}
};

#endif
