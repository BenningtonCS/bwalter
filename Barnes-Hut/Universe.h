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
		Point halfDimension;	// half the side length of the universe
};

#endif
