#include <Scene.h>

Scene::Scene(Camera cam) { setCamera(cam); }

Camera Scene::getCamera() { return camera; }
bool Scene::setCamera(Camera cam) { camera = cam; return true; }

void Scene::addObject(Object obj) {
    objs.push_back(obj);
}

bool Scene::sendRay(Ray3 ray) {
    if (objs[0].isHit(ray))
        return true;
    return false;
}
