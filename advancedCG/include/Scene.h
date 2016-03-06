#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <Objects.h>
#include <Camera.h>
#include <Ray3.h>

class Scene {
  protected:
    std::vector<Object> objs;
    Camera camera;

  public:
    Scene(Camera);

    Camera getCamera();
    bool setCamera(Camera);

    void addObject(Object);

    bool sendRay(Ray3);
};

#endif
