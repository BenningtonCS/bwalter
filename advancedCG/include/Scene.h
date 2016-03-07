/*
    Scene.h
    2016 March 2
    Brendon Walter

    Class for creating the scene.

    The scene holds everything to be rendered: Every object, camera, and lights.

    TODO: Make getter function to return the objects in the scene
    TODO: Make the scene take a vector of camera so you can render from multiple
            angles?
    TODO: Add background color
*/

#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <Objects.h>
#include <Camera.h>
#include <Ray3.h>

class Scene {
  protected:
    std::vector<Object*> objs;      // objects in the scene (empty by default)
    Camera camera;

  public:

    /* constructors */

    Scene(Camera);                  // scene must have a camera set


    /* getters */

    /*
    Paramters: None
    Returns: Camera and objects in the scene
    */
    Camera getCamera();

    /* setters */

    /*
    Parameters: Camera or objects to add to the scene
    Returns: true if set correctly, false if not
    */
    bool addCamera(Camera);
    void addObject(Object*);

    /*
    Parameters: Ray3 to shoot into the scene
    Returns: The color of the object it hits. If nothing is hit, this color
        is the color of the background of the scene
    */
    Color sendRay(Ray3);
};

#endif
