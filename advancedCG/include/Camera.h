/*
    Camera.h
    2016 March 2
    Brendon Walter

    Class for creating a camera.
*/

#ifndef CAMERA_H
#define CAMERA_H

#include <math.h>

#include <Vector3.h>
#include <Canvas.h>
#include <Ray3.h>

class Scene;

class Camera {
  protected:
    Vector3 location;   // Location of the camera (0, 0, -10) by default
    Vector3 lookAt;     // Where the camera is looking (0, 0, 0) by default
    Canvas canvas;      // 800x600 pixel image by default
    float pixelSize;    // size of each pixel in the world

    Vector3 u, v, w;    // orthonormal basis

    bool setUVW(const Vector3&, const Vector3&, const Vector3&);

  public:

    /* getters */

    /*
    Paramters: None
    Returns: The location or lookAt as a Vector3, the canvas, or the size of
        each pixel as a float.
    */
    Vector3 getLocation() const;
    Vector3 getLookAt() const;
    Canvas getCanvas() const;
    float getPixelSize() const;

    Vector3 getu() const;
    Vector3 getv() const;
    Vector3 getw() const;


    /* setters */

    /*
    Paramters: Location of the camera as either a Vector3 or in (x, y, z) format
    Returns: true if set correctly, false if not
    */
    bool setLocation(const Vector3&);
    bool setLocation(const double, const double, const double);

    /*
    Parameters: LookAt of the camera as either a Vector3 or in (x, y, z) format
    Returns: true if set correctly, false if not
    */
    bool setLookAt(const Vector3&);
    bool setLookAt(const double, const double, const double);

    /*
    Paramters: Width and height of the canvas as integers
    Returns: true if set correctly, false if not
    */
    bool setCanvas(const int, const int);

    /*
    Parameters: Set the size of each pixel in the rendered world
    Returns: true if set correctly, false if not
    */
    bool setPixelSize(const float);

    /* class methods */

    /*
    Paramters: Scene to be rendered, name of the file to write to
    Returns: None

    Renders a scene and writes it to a .bmp file
    */
    virtual void render(const Scene&, const char*);

    /* Set up orthonormal basis */
    void setupUVW();

    Vector3 vectorToWorldCoordinates(const Vector3&) const;
    Vector3 pointToWorldCoordinates(const Vector3&) const;

};


class OrthographicCam: public Camera {

  public:
    /* constructors */

    OrthographicCam();
    OrthographicCam(const Vector3&, const Vector3&);        // location, lookAt
    OrthographicCam(const double, const double, const double,  // location
                    const double, const double, const double); // lookAt


    void render(const Scene&, const char*);
};


class PerspectiveCam: public Camera {
  protected:
    double FOV;

    double getDistance() const;

  public:
    PerspectiveCam();
    PerspectiveCam(const Vector3&, const Vector3&, const double);
    PerspectiveCam(const double, const double, const double,  // location
                   const double, const double, const double, // lookAt
                   const double);


    double getFOV() const;

    bool setFOV(const double);

    void render(const Scene&, const char*);
};

#endif
