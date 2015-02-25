/*
	Universe.cpp
	2014 December 11
	Brendon Walter

	Operator overloading for Point struct	
*/

#include "Universe.h"

bool operator== (Point &p1, Point &p2) {
	return (p1.x == p2.x &&
			p2.y == p2.y);
}
bool operator!= (Point &p1, Point &p2) {
	return !(p1 == p2);
}
