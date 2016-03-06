#include <Scene.h>

Scene::Scene(Camera cam) { setCamera(cam); }

Camera Scene::getCamera() { return camera; }
bool Scene::setCamera(Camera cam) { camera = cam; return true; }

void Scene::addObject(Object* obj) {
    objs.push_back(obj);
}

Color Scene::sendRay(Ray3 ray) {
    for (unsigned int i=0; i<objs.size(); i++) {
        if (objs[i]->isHit(ray))
            return objs[i]->getColor();
    }
    Color color(1,1,1,1);   //TODO: Change this to a preset background color
    return color;
}
