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
		
		void setSize(int pixels) {
			size = pixels;
			center.x = center.y = pixels / 2;
		}

		int getSize() {
			return size;
		}

		Point getCenter() {
			return center;
		}
};

#endif
