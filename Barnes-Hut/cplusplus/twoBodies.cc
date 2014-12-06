/*
	twoBodies.cc
	2014 December 5
	Brendon Walter

	Two bodies interacting through gravity
*/

#include <iostream>
#include <cmath>

#define G 6.67 * pow(10, -11) 
#define X 0
#define Y 1

using namespace std;

class Body {

	private:
		double mass;	// mass
		double r[2];	// x, y position
		double v[2];	// x, y velocity

	public:
		
		void newBody(double m, double x, double y, double vx, double vy) {
			mass = m;
			r[X] = x;  r[Y] = y;
			v[X] = vx; v[Y] = vy;
		}	

		void calcForce(Body m2, double Fg[]) {
			double distance = sqrt(pow(r[X] - m2.r[X], 2) + 
								   pow(r[Y] - m2.r[Y], 2));
			
			double force = (G * mass * m2.mass) / pow(distance, 2);
			Fg[X] = force * (r[X] - m2.r[X]) / distance;
			Fg[Y] = force *	(r[Y] - m2.r[Y]) / distance;
		}

		void move(Body m2) {
			double Fg[2];
			calcForce(m2, Fg);
	
			double a[2];
			a[X] = Fg[X] / mass;
			a[Y] = Fg[Y] / mass;
		}
};

int main(void) {

}
