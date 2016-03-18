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
      Color getColor() const;


      /* setters */

      bool setColor(const Color&);


      /* class methods */

      /* methods overloaded in child classes */
      virtual float rayHitPosition(const Ray3&) const;
      virtual Vector3 getNormal(const Vector3&) const;
};


/* S P H E R E */

class Sphere: public Object {
  protected:
    Vector3 center;     // (0, 0, 0) by default
    double radius;      // 1 by default

  public:

    /* constructors */

    Sphere();

    Sphere(const Vector3&, const double);               // center, radius

    Sphere(const Vector3&, const double, const Color&); // center, radius, color

    Sphere(const double, const double, const double,    // center as (x, y, z)
           const double);                               // radius

    Sphere(const double, const double, const double,    // center as (x, y, z)
           const double, const Color&);                 // radius, color


    /* getters */

    /*
    Paramters: None
    Returns: The center of the sphere as a Vector3 or the radius as a double
    */
    Vector3 getCenter() const;
    double getRadius() const;


    /* setters */

    /*
    Parameters: Center as either a Vector3 or doubles
    Returns: true if set correctly, false if not
    */
    bool setCenter(const Vector3&);
    bool setCenter(const double, const double, const double);

    /*
    Paramters: Radius as a doubles
    Returns: true if set correctly, false if not
    */
    bool setRadius(const double);

    /*
    Paramters:
        center - as either a Vector3 or 3 doubles
        radius - as a double
        color - as a Color (optional. This will be white be default)
    Returns: true if set correctly, false if not
    */
    bool setSphere(const Vector3&, const double);
    bool setSphere(const Vector3&, const double, const Color&);
    bool setSphere(const double, const double, const double,
                   const double);
    bool setSphere(const double, const double, const double,
                   const double, const Color&);


    /* class methods */

    /*
    Paramters: Position on the sphere as a Vector3
    Returns: The normal vector at that position
    */
    Vector3 getNormal(const Vector3 &) const;

    /*
    Paramters: Ray to being sent into the Scene
    Returns: Position of where the ray intersects with the sphere. If it doens't
        hit, (-1, -1, -1) is returned instead.

    Check if a ray intersects with the sphere
    */
    float rayHitPosition(const Ray3&) const;
};

#endif
