/*
    Scene.h
    2016 March 2
    Brendon Walter

    Class for creating the scene.

    The scene holds everything to be rendered: Every object, camera, and lights.

    TODO: Make getter function to return the objects in the scene
    TODO: Make the scene take a vector of camera so you can render from multiple
            angles?
*/

#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <Objects.h>
#include <Camera.h>
#include <Ray3.h>
#include <Lights.h>

class Scene {
  protected:
    Camera camera;                  // camera to render the scene
    std::vector<Object*> objs;      // objects in the scene (empty by default)
//    std::vector<Light*> lights;     // lights in the scene (empty by default)
    DirectionalLight light;
    Color background;               // background color. (black by default)

  public:

    /* constructors */

    Scene(Camera);                  // scene must have a camera set


    /* getters */

    /*
    Paramters: None
    Returns: Camera or objects in the scene, or the background color
    */
    Camera getCamera();
    Color getBackground();
    std::vector<Object*> getObjects();

    /* setters */

    /*
    Paramters: Color of the background as either a Color or as RGBA values
    Returns: true if set correctly, false if not
    */
    bool setBackground(Color);
    bool setBackground(float, float, float, float);

    /*
    Parameters: Camera or objects to add to the scene
    Returns: true if set correctly, false if not
    */
    bool addCamera(Camera);
    bool addObject(Object*);
    bool addLight(DirectionalLight);

    /*
    Parameters: Ray3 to shoot into the scene
    Returns: The color of the object it hits. If nothing is hit, this color
        is the color of the background of the scene
    */
    Color sendRay(Ray3);
};

#endif
