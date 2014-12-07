#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "Body.h"
#include "Universe.h"

#define G 6.67 * pow(10, -11)	// gravitational constant
#define UNIVERSE 750

/*
	Parameters: mass, positions in x and y, velocities in x and y
	Returns: None
	Create a new body with the values given in the paramter
*/		
void Body::makeBody(double m, double x, double y, double vx, double vy) {
	mass = m;
	pos.x = x;	pos.y = y;
	vel.x = vx;	vel.y = vy;
}

/*
	 generate a random number between 0 and range
*/
double Body::randomNum(double range) {
	return  (rand()) / (RAND_MAX / range);
}
/*
	Parameters: Range in which the bodies can be positioned
	Returns: None
	Make a new body at a random position and with random a random velocity
*/
void Body::makeRandomBody(double range) {
	mass = 100;

	// get random position
	pos.x = randomNum(range);	pos.y = randomNum(range);

	// get random velocity
//	vel.x = randomNum(0.1);	vel.y = randomNum(0.1);
}

/*
	Parameters: Other interacting body
	Returns: None
	Calculates the graviational force between two interacting bodies
*/
void Body::calcForce(Body m2) {
	Point Fg;
	double epsilon = pow(3, 4);	// softening parameter
	
	// calculate distance between the two objects
	double distance = sqrt(pow(pos.x - m2.pos.x, 2) + 
						   pow(pos.y - m2.pos.y, 2));
	// calculate the graviational force
	double force = (G * mass * m2.mass) / 
				   (pow(distance, 2) + pow(epsilon, 2));

	// break force into x and y componants
	Fg.x = force * (m2.pos.x - pos.x) / distance;
	Fg.y = force * (m2.pos.y - pos.y) / distance;
}

/*
	Parameters: Time step
	Returns: None
	Updates each value of the body
*/
void Body::update(double dt) {

	// update velocity
	vel.x += dt * force.x / mass;
	vel.y += dt * force.y / mass;

	// update position
	std::cout << vel.x <<std::endl;
	pos.x += dt * vel.x;
	pos.y += dt * vel.y;
}

/*
	Parameters: None
	Returns: None
	Resets the force on each object to 0
*/
void Body::resetForce() {
	force.x = 0;
	force.y = 0;
} 

