/*
    Camera.h
    2016 March 2
    Brendon Walter

    Class for creating a camera.
*/

#ifndef CAMERA_H
#define CAMERA_H

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

  public:

    /* constructors */

    Camera();
    Camera(Vector3, Vector3);           // location, lookAt
    Camera(double, double, double,      // location as (x, y, z) coords
           double, double, double);     // lookAt as (x, y, z) coords


    /* getters */

    /*
    Paramters: None
    Returns: The location or lookAt as a Vector3, the canvas, or the size of
        each pixel as a float.
    */
    Vector3 getLocation();
    Vector3 getLookAt();
    Canvas getCanvas();
    float getPixelSize();


    /* setters */

    /*
    Paramters: Location of the camera as either a Vector3 or in (x, y, z) format
    Returns: true if set correctly, false if not
    */
    bool setLocation(Vector3);
    bool setLocation(double, double, double);

    /*
    Parameters: LookAt of the camera as either a Vector3 or in (x, y, z) format
    Returns: true if set correctly, false if not
    */
    bool setLookAt(Vector3);
    bool setLookAt(double, double, double);

    /*
    Paramters: Width and height of the canvas as integers
    Returns: true if set correctly, false if not
    */
    bool setCanvas(int, int);

    /*
    Parameters: Set the size of each pixel in the rendered world
    Returns: true if set correctly, false if not
    */
    bool setPixelSize(float);


    /* class methods */

    /*
    Paramters: Scene to be rendered, name of the file to write to
    Returns: None

    Renders a scene and writes it to a .bmp file
    */
    void render(Scene, char*);

};

#endif
