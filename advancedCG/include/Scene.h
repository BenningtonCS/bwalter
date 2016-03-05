#ifndef SCENE_H
#define SCENE_H

#include <Sphere.h>
#include <Camera.h>
#include <Ray3.h>

class Scene {
  protected:
    Sphere sphere;
    Camera camera;

  public:
    Scene(Camera);

    Camera getCamera();

    void setSphere(Sphere);
    bool setCamera(Camera);

    bool sendRay(Ray3);
};

#endif
