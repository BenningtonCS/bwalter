#include <Camera.h>
#include <Canvas.h>
#include <Color.h>
#include <Objects.h>
#include <Ray3.h>
#include <Scene.h>
#include <Vector3.h>

int main(void) {


    Color red(1, 0, 0, 1);
    Color yellow(1, 1, 0, 1);
    Color green(0, 1, 0, 1);
    Color blue(0, 0, 1, 1);
    Color white(1, 1, 1, 1);

    Material mat(.01);

    Sphere sphere1(0, 0, 100, 100, red);
    Sphere sphere2(150, -20, -200, 50, blue);
    sphere1.setMaterial(mat);
    sphere2.setMaterial(mat);

    Box box;

    Plane plane(0, 1, 0, 0, -50, 0, white);
    Disk disk(-1, -1, -1, 150, -50, 10, 50, green);

    Vector3 dir(80, 100, 50);
//    DirectionalLight light(dir);
    PointLight light(dir);
    Vector3 dir2(-80, 0, -50);
    PointLight light2(dir2);

    light.setColor(green);

//    OrthographicCam cam;
    PerspectiveCam cam;

    Scene scene(cam);
    scene.addObject(&sphere1);
    scene.addObject(&sphere2);
    scene.addObject(&plane);
//    scene.addObject(&box);
//    scene.addObject(&disk);
//    scene.addLight(&light);
    scene.addLight(&light2);

    cam.render(scene, "sphere.bmp");
}
