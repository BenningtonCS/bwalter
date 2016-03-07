#include <Scene.h>

/* constructors */

Scene::Scene(Camera cam) { addCamera(cam); }


/* getters */

Camera Scene::getCamera() { return camera; }


/* setters */

bool Scene::addCamera(Camera cam) { camera = cam; return true; }
void Scene::addObject(Object* obj) {
    objs.push_back(obj);
}


/* class methods */

Color Scene::sendRay(Ray3 ray) {
    // check if the ray hits an object in the scene
    // TODO: find a way to check if there's objects infront/behind eachother
    for (unsigned int i=0; i<objs.size(); i++) {
        if (objs[i]->isHit(ray))
            return objs[i]->getColor();
    }
    Color color(1,1,1,1);   //TODO: Change this to a preset background color
    return color;
}
