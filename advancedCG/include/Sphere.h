/*
    Sphere.h
    2016 March 2
    Brendon Walter

    Class for creating a sphere.

    Methods can be found in src/Sphere.cpp
*/

#ifndef SPHERE_H
#define SPHERE_H

#include <Vector3.h>
#include <Color.h>

class Sphere {
  protected:
    Vector3 center;
    double radius;
    Color color;

  public:

    /* constructors */

    Sphere();
    Sphere(Vector3, double);
    Sphere(Vector3, double, Color);
    Sphere(double, double, double, double);
    Sphere(double, double, double, double, Color);


    /* getters */

    Vector3 getCenter();
    double getRadius();
    Color getColor();
    void getSphere(Vector3*, double*, Color*);
    void getSphere(double*, double*, double*, double*, Color*);


    /* setters */

    bool setCenter(Vector3);
    bool setCenter(double, double, double);
    bool setRadius(double);
    bool setColor(Color);
    bool setSphere(Vector3, double);
    bool setSphere(Vector3, double, Color);
    bool setSphere(double, double, double, double);
    bool setSphere(double, double, double, double, Color);
};

#endif
