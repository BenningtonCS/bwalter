/*
    Objects.h
    2016 March 6
    Brendon Walter

    Abstract object class and various shapes inherited from that class.

    Shapes include: Spheres, and more to come
*/

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

      /* getters */

      /*
      Parameters: None
      Returns: The color of the object
      */
      Color getColor();


      /* setters */

      bool setColor(Color);


      /* class methods */

      /* methods overloaded in child classes */
      virtual float rayHitPosition(Ray3);
      virtual Vector3 getNormal(Vector3);
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
    Returns: true if set correctly, false if not
    */
    bool setSphere(Vector3, double);
    bool setSphere(Vector3, double, Color);
    bool setSphere(double, double, double, double);
    bool setSphere(double, double, double, double, Color);


    /* class methods */

    /*
    Paramters: Ray to being sent into the Scene
    Returns: Position of where the ray intersects with the sphere. If it doens't
        hit, (-1, -1, -1) is returned instead.

    Check if a ray intersects with the sphere
    */
    float rayHitPosition(Ray3);

    /*
    Paramters: Position on the sphere as a Vector3
    Returns: The normal vector at that position
    */
    Vector3 getNormal(Vector3);
};

#endif
