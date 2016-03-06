#include <Camera.h>
#include <Canvas.h>
#include <Color.h>
#include <Objects.h>
#include <Ray3.h>
#include <Scene.h>
#include <Vector3.h>

int main(void) {

    Sphere sphere(200, 300, 10, 100);
    Color color(1, 0, 0, 1);
    sphere.setColor(color);

    Camera cam;

    Scene scene(cam);
    scene.addObject(sphere);

    cam.render(scene, "sphere.bmp");
}
