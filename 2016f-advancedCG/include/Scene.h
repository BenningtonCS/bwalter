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
#include <limits>

#include <Objects.h>
#include <Camera.h>
#include <Ray3.h>
#include <Lights.h>

class Scene {
  protected:
    Camera camera;                  // camera to render the scene
    std::vector<Object*> objs;      // objects in the scene (empty by default)
    std::vector<Light*> lights;     // lights in the scene (empty by default)
    Color background;               // background color. (black by default)
    int maxDepth = 10;              // maximum depth of relfections

  public:

    /* constructors */

    Scene(const Camera&);           // scene must have a camera set


    /* getters */

    /*
    Paramters: None
    Returns: Camera or objects in the scene, or the background color
    */
    Camera getCamera() const;
    Color getBackground() const;
    std::vector<Object*> getObjects() const;

    /* setters */

    /*
    Paramters: Color of the background as either a Color or as RGBA values
    Returns: true if set correctly, false if not
    */
    bool setBackground(const Color&);
    bool setBackground(const float, const float, const float, const float);

    /*
    Parameters: Camera or objects to add to the scene
    Returns: true if set correctly, false if not
    */
    bool addCamera(const Camera&);
    bool addObject(Object*);
    bool addLight(Light*);


    /* class methods */

    /*
    Parameters: Ray3 to shoot into the scene
    Returns: The color of the object it hits. If nothing is hit, this color
        is the color of the background of the scene
    */
    Color sendRay(const Ray3&) const;

    Color sendRay(const Ray3&, const int) const;
};

#endif
