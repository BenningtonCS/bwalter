#include <Camera.h>
#include <Canvas.h>
#include <Color.h>
#include <Objects.h>
#include <Ray3.h>
#include <Scene.h>
#include <Vector3.h>

int main(void) {


    Color red(1, 0, 0, 1);
    Color blue(0, 0, 1, 1);
    Color white(1, 1, 1, 1);

    Sphere sphere1(0, 0, 100, 100, red);
    Sphere sphere2(-150, -50, 100, 50, blue);

    Plane plane(0, 0, -1, 0, 0, 100);
    plane.setColor(white);

    Vector3 dir(1, -1, 1);
    DirectionalLight light(dir);

    Camera cam;

    Scene scene(cam);
    scene.addObject(&sphere1);
    scene.addObject(&sphere2);
    scene.addObject(&plane);
    scene.addLight(&light);

    cam.render(scene, "sphere.bmp");
}
