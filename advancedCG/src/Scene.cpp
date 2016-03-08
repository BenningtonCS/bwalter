#include <Scene.h>

/* constructors */

Scene::Scene(Camera cam) {
    addCamera(cam);
    setBackground(1, 1, 1, 1);
}


/* getters */

Camera Scene::getCamera() { return camera; }
Color Scene::getBackground() { return background; }
std::vector<Object*> Scene::getObjects() { return objs; }


/* setters */

bool Scene::setBackground(Color col) {
    background = col;
    return true;
}

bool Scene::setBackground(float r, float g, float b, float a) {
    Color col(r, g, b, a);
    background = col;
    return true;
}

bool Scene::addCamera(Camera cam) { camera = cam; return true; }
bool Scene::addObject(Object* obj) {
    objs.push_back(obj);
    return true;
}


/* class methods */

Color Scene::sendRay(Ray3 ray) {
    // check if the ray hits an object in the scene
    // TODO: find a way to check if there's objects infront/behind eachother
    for (unsigned int i=0; i<objs.size(); i++) {
        if (objs[i]->isHit(ray))
            return objs[i]->getColor();
    }

    return background;
}
