#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#define UNIVERSE 100			// size of the universe
#define NUM_BODIES 10			// number of particles in simulation
#define G 6.67 * pow(10, -11)	// gravitational constant

using namespace std;

// x and y values for positions and vectors (velocity, force, acceleration)
typedef struct {
	double x;
	double y;
} Point;


// 
class Universe {

	private:
		Point center;			// coordinates for the center of the universe
		Point halfDimension;	// half the side length of the universe
};

class Body {

	private:
		double mass;		// mass of the particle
		Point pos;			// x, y coordinates
		Point vel;			// velocity in x and y

	public:

		/*
			Parameters: mass, positions in x and y, velocities in x and y
			Returns: None
			Create a new body with the values given in the paramter
		*/		
 		void makeBody(double m, double x, double y, double vx, double vy) {
			mass = m;
			pos.x = x;	pos.y = y;
			vel.x = x;	vel.y = y;
		}

		/*
			 generate a random number between -range and +range
		*/
		double randomNum(int range) {
			return rand() % range*2 + (-range);
		}
	
		/*
			Parameters: None
			Returns: None
			Make a new body at a random position and with random a random velocity
		*/
		void makeRandomBody() {
			mass = 1;
			
			// get random position
			pos.x = randomNum(10);	pos.y = randomNum(10);

			// get random velocity
			vel.x = randomNum(10);	vel.y = randomNum(10);
		}

		/*
			Parameters: Other interacting body
			Returns: Resulting gravitational force
			Calculates the graviational force between two interacting bodies
		*/
		Point calcForce(Body m2) {
			Point Fg;

			// calculate distance between the two objects
			double distance = srt(pow(pos.x - m2.pos.x, 2) + 
								  pow(pos.y - m2.pos.y, 2));
			// calculate the graviational force
			double force = (G * mass * m2.mass) / pow(distance, 2);

			// break force into x and y componants
			Fg.x = force * (pos.x - m2.pos.x) / distance;
			Fg.y = force * (pos.y - m2.pos.y) / distance;

			return Fg;
		}
};



int main(void) {
	srand(time(NULL));
}
