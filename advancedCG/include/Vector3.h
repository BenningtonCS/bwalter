/*
    Vector3.h
    2016 February 29
    Brendon Walter

    Class for creating vectors in 3D space. A vector has a direction and a
    magnitude, expressed in this implementation as a (x, y, z) coordinate.

    Methods can be found in src/Vector3.cpp
*/

#ifndef VECTOR3_H
#define VECTOR3_H

#include <stdio.h>
#include <cmath>

class Vector3 {
  protected:
    double x, y, z;

  public:

     /* constructors */

    Vector3();                          // (0, 0, 0) by default
    Vector3(double, double, double);    // x, y, z


    /* getters */

    /*
    Parameters: None
    Returns: value of x, y, or z coordinate
    */
    double getx() const;
    double gety() const;
    double getz() const;

    /*
    Parameters:
        output: doubles to store x, y, and z coordinates
    Returns: None
    */
    void getVector(double*, double*, double*) const;


    /* setters */

    /*
    Parameters: x, y, or z coordinate componant as a double
    Returns: true if set correctly, false if not
    */
    bool setx(double);
    bool sety(double);
    bool setz(double);

    /*
    Parameters: x, y, and z coodinates as doubles
    Returns: true if set correctly, false if not
    */
    bool setVector(double, double, double);


    /* method functions */

    /*
    Parameters: None
    Returns: Magnitude of the ray as a double

    Get the magnitude of the vector
    */
    double getMagnitude() const;

    /*
    Parameters: None
    Returns: The square of the magnitude of the ray as a double

    Get the square of the magnitude of the vector
    */
    double getMagnitudeSquared() const;

    /*
    Parameters: None
    Returns: A vector with a total magnitude of 1

    Convert a Vector3 into a unit vector
    */
    Vector3 makeUnitVector() const;

    /*
    Parameters: None
    Returns: None

    Print the vector to the screen as (x, y, z)
    */
    void printVector() const;

    /*
    Parameters: Vector3 to cross the vector with
    Returns: the cross product as a Vector3

    Get the cross product of two vectors
    */
    Vector3 cross(Vector3) const;

    /* operator over loads */

    Vector3 operator+(Vector3) const;  // addition
    Vector3 operator-(Vector3) const;  // subtraction
    Vector3 operator*(double) const;   // multiplcation by a scalar
    Vector3 operator/(double) const;   // division by a scalar
    double operator*(Vector3) const;   // dot product
    bool operator==(Vector3) const;    // equals
    bool operator!=(Vector3) const;    // not equals
};

#endif
