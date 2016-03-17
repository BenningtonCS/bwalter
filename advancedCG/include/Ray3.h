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
    Vector3 origin;         // (0, 0, 0)
    Vector3 direction;      // (1, 1, 1)

  public:
    Ray3();
    Ray3(const Vector3&, const Vector3&);             // origin, direction
    Ray3(const double, const double, const double,    // x, y, z of origin
         const double, const double, const double);   // x, y, z of direction

    /*
    Parameters: None
    Returns: Origin or direction of ray as a Vector3
    */
    Vector3 getOrigin() const;
    Vector3 getDirection() const;

    /*
    Parameters: Origin or direction of the ray as a Vector3
    Return: true if set correctly, false if not
    */
    bool setOrigin(const Vector3&);
    bool setDirection(const Vector3&);

    /*
    Parameters: componants of origin or direction of the ray as doubles
    Returns: true if set correctly, false if not
    */
    bool setOrigin(const double, const double, const double);
    bool setDirection(const double, const double, const double);

    /*
    Parameters: origin and direction of the ray as either Vector3s or doubles
    Returns: true if set correctly, false if not
    */
    bool setRay(const Vector3&, const Vector3&);
    bool setRay(const double, const double, const double,
                const double, const double, const double);

    /*
    Parameters: None
    Returns: None

    Print the origin and the direction as (x, y, z), (x, y, z) respectively
    */
    void printRay() const;

    Vector3 rayAtT(const float) const;
};

#endif
