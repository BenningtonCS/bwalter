/*
    Sphere.h
    2016 March 2
    Brendon Walter

    Class for creating a sphere.

    Methods can be found in src/Sphere.cpp
*/

#ifndef SPHERE_H
#define SPHERE_H

#include <algorithm>

#include <Vector3.h>
#include <Color.h>
#include <Ray3.h>

class Sphere {
  protected:
    Vector3 center;
    double radius;
    Color color;

  public:

    /* constructors */

    Sphere();                       // center: (0,0,0), radius: 1, color: white
    Sphere(Vector3, double);        // center, radius
    Sphere(Vector3, double, Color); // center, radius, color
    Sphere(double, double, double, double); // (x, y, z) of center, radius
    Sphere(double, double, double, double, Color); // (x, y, z), radius, color


    /* getters */

    /*
    Paramters: None
    Returns: The center of the sphere as a Vector3, the radius as a double, or
        the color of the sphere as a Color.
    */
    Vector3 getCenter();
    double getRadius();
    Color getColor();

    /*
    Paramters:
       output: Vector3, double, and Color to hold the center, radius, and color
            of the sphere
    Returns: None
    */
    void getSphere(Vector3*, double*, Color*);

    /*
    Paramters:
       output: doubles for the center and radius and color of the sphere
    Returns: None
    */
    void getSphere(double*, double*, double*, double*, Color*);


    /* setters */

    /*
    Parameters: Center as either a Vector3 or doubles
    Returns: true if set correctly, false if not
    */
    bool setCenter(Vector3);
    bool setCenter(double, double, double);

    /*
    Paramters: Radius as a doubles
    Returns: true if set correctly, false if not
    */
    bool setRadius(double);

    /*
    Parameters: Color of the setSphere
    Returns: true if set correctly, false if not
    */
    bool setColor(Color);

    /*
    Paramters:
        center - as either a Vector3 or doubles
        radius - as a double
        color - as a Color (optional. This will be white be default)
    */
    bool setSphere(Vector3, double);
    bool setSphere(Vector3, double, Color);
    bool setSphere(double, double, double, double);
    bool setSphere(double, double, double, double, Color);

    bool isHit(Ray3);
};

#endif
