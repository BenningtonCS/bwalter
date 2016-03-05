#include <Camera.h>
#include <Canvas.h>
#include <Color.h>
#include <Vector3.h>
#include <Ray3.h>
#include <Sphere.h>
#include <Scene.h>

int main(void) {

    Sphere sphere;
    Color color(1, 0, 0, 1);
    sphere.setColor(color);

    Camera cam;

    Scene scene(cam);
    scene.setSphere(sphere);

    cam.render(scene);
/*
		int width = 800;
		int height = 600;

		Canvas c(width, height);
		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				//if (x == y) c.setPixel(x, y, red);
        //else c.setPixel(x, y, blue);
        Color gradient(0, 1-(float)x/width, 0+(float)x/width, 1);
        c.setPixel(x, y, gradient);
			}
		}
		c.writeToFile("output.bmp");
*/
}
