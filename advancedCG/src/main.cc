#include <Camera.h>
#include <Canvas.h>
#include <Color.h>
#include <Vector3.h>
#include <Ray3.h>
#include <Sphere.h>
#include <Scene.h>

int main(void) {

    Sphere sphere(200, 300, 10, 100);
    Color color(1, 0, 0, 1);
    sphere.setColor(color);

    Camera cam;

    Scene scene(cam);
    scene.setSphere(sphere);

    cam.render(scene);
}
