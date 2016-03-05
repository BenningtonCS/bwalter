#ifndef CAMERA_H
#define CAMERA_H

#include <Vector3.h>
#include <Canvas.h>
#include <Ray3.h>

class Scene;

class Camera {
  protected:
    Vector3 location;   // (0, 0, -10) by default
    Vector3 lookAt;     // (0, 0, 0) by default
    Canvas canvas;      // 800x600 pixel image by default
    float pixelSize;

  public:

    /* constructors */

    Camera();
    Camera(Vector3, Vector3);


    /* getters */

    Vector3 getLocation();
    Vector3 getLookAt();
    Canvas getCanvas();
    float getPixelSize();


    /* setters */

    bool setLocation(Vector3);
    bool setLocation(double, double, double);
    bool setLookAt(Vector3);
    bool setLookAt(double, double, double);
    bool setCanvas(int, int);
    bool setPixelSize(float);


    /* class methods */

    void render(Scene);

};

#endif
