#ifndef OBJECTS_H
#define OBJECTS_H

#include <algorithm>

#include <Vector3.h>
#include <Ray3.h>
#include <Color.h>

class Object {
  protected:
      Color color;      // white by default

  public:
      Color getColor();
      bool setColor(Color);

      virtual bool isHit(Ray3);
};


/* S P H E R E */

class Sphere: public Object {
  protected:
    Vector3 center;     // (0, 0, 0) by default
    double radius;      // 1 by default

  public:

    /* constructors */

    Sphere();
    Sphere(Vector3, double);                    // center, radius
    Sphere(Vector3, double, Color);             // center, radius, color
    Sphere(double, double, double, double);     // (x, y, z), radius
    Sphere(double, double, double, double, Color); // (x, y, z), radius, color


    /* getters */

    /*
    Paramters: None
    Returns: The center of the sphere as a Vector3 or the radius as a double
    */
    Vector3 getCenter();
    double getRadius();

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
    Paramters:
        center - as either a Vector3 or 3 doubles
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
