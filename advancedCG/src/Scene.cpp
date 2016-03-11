#include <stdio.h>

#include <Scene.h>

/* constructors */

Scene::Scene(Camera cam) {
    addCamera(cam);
    setBackground(0, 0, 0, 1);

    DirectionalLight l;
    addLight(l);
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
bool Scene::addLight(DirectionalLight l) { light = l; return true; }


/* class methods */

Color Scene::sendRay(Ray3 ray) {
    // check if the ray hits an object in the scene
    // TODO: find a way to check if there's objects infront/behind eachother
    Vector3 nullVector(-1, -1, -1);
    Color color;

    for (unsigned int i=0; i<objs.size(); i++) {
        Vector3 hitPos = objs[i]->rayHitPosition(ray);

        if (hitPos != nullVector) {

            float intensity = light.getIntensity(hitPos);
            if (intensity < 0)
                intensity = 0;

            color.setColor(objs[i]->getColor().getr()*intensity,
                           objs[i]->getColor().getg()*intensity,
                           objs[i]->getColor().getb()*intensity,
                           objs[i]->getColor().geta());
            return color;
        }
    }

    return background;
}
