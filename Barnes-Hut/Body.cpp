/*
	Body.cpp
	2014 December 5
	Brendon Walter

	Methods for Body class
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "Body.h"

#define G 6.67 * pow(10, -11)	// gravitational constant
#define UNIVERSE 750

// comparison functions for Body
bool operator== (Body &m1, Body &m2) {
	return (m1.mass == m2.mass &&
			m1.pos == m2.pos &&
			m1.vel == m2.vel &&
			m1.force == m2.force);
}

bool operator!= (Body &m1, Body &m2) {
	return !(m1 == m2);
}

/*
	Parameters: None
	Returns: None
	Creates a new body with 0 set for all values
*/
void Body::makeEmptyBody() {
	mass = 0;
	pos.x = pos.y = 0;
	vel.x = vel.y = 0;
	force.x = force.y = 0;
}

/*
	Parameters: mass, positions in x and y, velocities in x and y
	Returns: None
	Create a new body with the values given in the paramter
*/		
void Body::makeBody(double m, double x, double y, double vx, double vy) {
	mass = m;
	pos.x = x;	pos.y = y;
	vel.x = vx;	vel.y = vy;
	force.x = force.y = 0;
}

/*
	 generate a random number between 0 and range
*/
double Body::randomNum(int min, int max) {
	return  (rand() % (max - min)) + min;
}
/*
	Parameters: Range in which the bodies can be positioned
	Returns: None
	Make a new body at a random position and with random a random velocity
*/
void Body::makeRandomBody(int min, int max) {
	mass = 1E5;

	// get random position
	pos.x = randomNum(min, max);	pos.y = randomNum(min, max);

	// get random velocity
	vel.x = vel.y = 0;
	force.x = force.y = 0;
}

/*
	Parameters: Other interacting body
	Returns: None
	Calculates the graviational force between two interacting bodies
*/
void Body::calcForce( Body m2) {
	double epsilon = pow(3, 4);	// softening parameter
	
	// calculate distance between the two objects
	double distance = sqrt(pow(pos.x - m2.pos.x, 2) + 
						   pow(pos.y - m2.pos.y, 2));
	// calculate the graviational force
	double Fg = (G * mass * m2.mass) / 
				   (pow(distance, 2) + pow(epsilon, 2));

	// break force into x and y componants
	force.x += Fg * (m2.pos.x - pos.x) / distance;
	force.y += Fg * (m2.pos.y - pos.y) / distance;
	
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

