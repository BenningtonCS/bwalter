#include <Camera.h>
#include <Canvas.h>
#include <Color.h>
#include <Objects.h>
#include <Ray3.h>
#include <Scene.h>
#include <Vector3.h>

int main(void) {


    Color red(1, 0, 0, 1);
    Color green(0, 1, 0, 1);
    Color blue(0, 0, 1, 1);
    Color white(1, 1, 1, 1);

    Material mat(.01);

    Sphere sphere1(0, 0, 100, 100, red);
    sphere1.setMaterial(mat);
    Sphere sphere2(-150, -50, 100, 50, blue);
    sphere2.setMaterial(mat);

    Plane plane(0, 0, -1, 0, 0, 100, white);
    Disk disk(-1, -1, -1, 150, -50, 10, 50, green);

    Vector3 dir(1, -1, 1);
    DirectionalLight light(dir);

    Camera cam;

    Scene scene(cam);
    scene.addObject(&sphere1);
    scene.addObject(&sphere2);
//    scene.addObject(&plane);
//    scene.addObject(&disk);
    scene.addLight(&light);

    cam.render(scene, "sphere.bmp");
}
