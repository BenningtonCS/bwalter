/*
    Ray3.h
    2016 February 29
    Brendon Walter

    Class for creating a ray in 3D space. A ray has an origin and a direction,
    both of which are represented as Vector3s in this implementation.

    Methods can be foudn in Ray3.cpp
*/

#ifndef RAY3_H
#define RAY3_H

#include <stdio.h>
#include <Vector3.h>

class Ray3 {
  protected:
    Vector3 origin;
    Vector3 direction;

  public:
    Ray3();                         // origin: (0, 0, 0), direction: (1, 0, 0)
    Ray3(Vector3, Vector3);
    Ray3(double, double, double,    // x, y, z of origin
         double, double, double);   // x, y, z of direction

    /*
    Parameters: None
    Returns: Origin or direction of ray as a Vector3
    */
    Vector3 getOrigin();
    Vector3 getDirection();

    /*
    Parameters:
        output: doubles to store the componants of the origin or direction
    Returns: None
    */
    void getOrigin(double*, double*, double*);
    void getDirection(double*, double*, double*);

    /*
    Parameters:
        output: doubles to store the componants of the origin and direction
    Returns: None
    */
    void getRay(double*, double*, double*, double*, double*, double*);


    /*
    Parameters: Origin or direction of the ray as a Vector3
    Return: true if set correctly, false if not
    */
    bool setOrigin(Vector3);
    bool setDirection(Vector3);

    /*
    Parameters: componants of origin or direction of the ray as doubles
    Returns: true if set correctly, false if not
    */
    bool setOrigin(double, double, double);
    bool setDirection(double, double, double);

    /*
    Parameters: origin and direction of the ray as either Vector3s or doubles
    Returns: true if set correctly, false if not
    */
    bool setRay(Vector3, Vector3);
    bool setRay(double, double, double, double, double, double);

    /*
    Parameters: None
    Returns: None

    Print the origin and the direction as (x, y, z), (x, y, z) respectively
    */
    void printRay();
};

#endif
