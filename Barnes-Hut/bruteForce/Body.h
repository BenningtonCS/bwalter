#ifndef BODY_H
#define BODY_H

#include "Universe.h"

class Body {

	public:

		double mass;		// mass of the particle
		Point pos;			// x, y coordinates
		Point vel;			// velocity in x and y
		Point acc;			// acceleration in x and y
		Point force;		// force in x and y


		/*
			Parameters: mass, positions in x and y, velocities in x and y
			Returns: None
			Create a new body with the values given in the paramter
		*/		
 		void makeBody(double m, double x, double y, double vx, double vy);

		/*
			 generate a random number between -range and +range
		*/
		double randomNum(int min, int max);

		/*
			Parameters: None
			Returns: None
			Make a new body at a random position and with random a random velocity
		*/
		void makeRandomBody(int min, int max); 

		/*
			Parameters: Other interacting body
			Returns: None
			Calculates the graviational force between two interacting bodies
		*/
		void calcForce(Body m2);


		/*
			Parameters: Time step
			Returns: None
			Updates each value of the body
		*/
		void update(double dt);

		/*
			Parameters: None
			Returns: None
			Resets the force on each object to 0
		*/
		void resetForce(); 

};

#endif
