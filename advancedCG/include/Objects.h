/*
    Objects.h
    2016 March 6
    Brendon Walter

    Abstract object class and various shapes inherited from that class.

    Shapes include: Spheres, planes, disks, boxes, and triangles
*/

#ifndef OBJECTS_H
#define OBJECTS_H

#include <algorithm>

#include <Vector3.h>
#include <Ray3.h>
#include <Color.h>
#include <Materials.h>

class Object {
  protected:
      Color color;      // white by default
      Material material;

  public:

      Object();

      /* getters */

      /*
      Parameters: None
      Returns: The color of the object
      */
      Color getColor() const;

      Material getMaterial() const;

      /* setters */

      bool setColor();
      bool setColor(const float, const float, const float, const float);
      bool setColor(const Color&);

      bool setMaterial(const Material&);


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


    /* class methods */

    /*
    Paramters: Position on the sphere as a Vector3
    Returns: The normal vector at that position
    */
    Vector3 getNormal(const Vector3&) const;

    /*
    Paramters: Ray to being sent into the Scene
    Returns: t of where the ray intersects with the sphere. If it doesn't hit,
        -1 is returned instead

    Check if a ray intersects with the sphere.
    */
    float rayHitPosition(const Ray3&) const;
};


/* P L A N E */

class Plane: public Object {
  protected:
    Vector3 normal;
    Vector3 point;

  public:

    /* constructors */

    Plane();
    Plane(const Vector3&, const Vector3&);               // normal, point

    Plane(const Vector3&, const Vector3&, const Color&); // normal, point, color

    Plane(const double, const double, const double,      // x, y, z of normal
          const double, const double, const double);     // x, y, z of point

    Plane(const double, const double, const double,      // x, y, z of normal
          const double, const double, const double,      // x, y, z of point
          const Color&);                                 // color



    /* getters */

    /*
    Paramters: None
    Returns: The normal or the point of the plane
    */
    Vector3 getNormal() const;
    Vector3 getPoint() const;


    /* setters */

    /*
    Paramters: The normal and/or point of the plane as either a Vector3 or in
        (x, y, z) componants as well as the color (optional)
    Returns: true if set correctly, false if not
    */
    bool setNormal(const Vector3&);
    bool setNormal(const double, const double, const double);

    bool setPoint(const Vector3&);
    bool setPoint(const double, const double, const double);


    /* class methods */

    Vector3 getNormal(const Vector3&) const;

    /*
    Parameters: Ray to be sent into the scene
    Returns: t of where the ray intersects with the plane. If it doesn't hit,
        -1 is returned instead

    Check if a ray intersects with the plane
    */
    float rayHitPosition(const Ray3&) const;
};


/* D I S K */

class Disk: public Object {
  protected:
    Vector3 normal;
    Vector3 center;
    float radius;

  public:

    /* constructors */

    Disk();
    Disk(const Vector3&, const Vector3&, const float);
    Disk(const Vector3&, const Vector3&, const float, const Color&);
    Disk(const double, const double, const double,
         const double, const double, const double,
         const float);
    Disk(const double, const double, const double,
         const double, const double, const double,
         const float, const Color&);


    /* getters */

    Vector3 getNormal() const;
    Vector3 getCenter() const;
    float getRadius() const;


    /* setters */

    bool setNormal(const Vector3&);
    bool setNormal(const double, const double, const double);

    bool setCenter(const Vector3&);
    bool setCenter(const double, const double, const double);

    bool setRadius(const float);


    /* class methods */
    Vector3 getNormal(const Vector3&) const;

    float rayHitPosition(const Ray3&) const;
};


/* B O X */

class Box: public Object {
  protected:
    Vector3 min;
    Vector3 max;

  public:

    /* constructors */

    Box();
    Box(const Vector3&, const Vector3&);
    Box(const Vector3&, const Vector3&, const Color&);
    Box(const double, const double, const double,
        const double, const double, const double);
    Box(const double, const double, const double,
        const double, const double, const double, const Color&);


    /* getters */

    Vector3 getMin() const;
    Vector3 getMax() const;


    /* setters */

    bool setMin(const Vector3&);
    bool setMin(const double, const double, const double);

    bool setMax(const Vector3&);
    bool setMax(const double, const double, const double);


    /* class methods */

    Vector3 getNormal(const Vector3&) const;
    float rayHitPosition(const Ray3&) const;
};

#endif
