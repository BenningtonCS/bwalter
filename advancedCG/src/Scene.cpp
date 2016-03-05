#include <Scene.h>

Scene::Scene(Camera cam) {
    setCamera(cam);
}

Camera Scene::getCamera() { return camera; }

void Scene::setSphere(Sphere sph) {
    sphere = sph;
}
bool Scene::setCamera(Camera cam) {
    camera = cam;
    return true;
}

bool Scene::sendRay(Ray3 ray) {
    if (sphere.isHit(ray))
        return true;
    return false;
}
