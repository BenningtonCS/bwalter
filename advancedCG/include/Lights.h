#ifndef LIGHTS_H
#define LIGHTS_H

#include <Color.h>
#include <Objects.h>
#include <Vector3.h>

class Light {
  protected:
    Color color;        // Color of the light. White by default

  public:

    /* getters */

    Color getColor();

    /* setters */

    bool setColor(Color);
    bool setColor(float, float, float, float);


    /* class methods */

    virtual float getIntensity(Vector3);
};

class DirectionalLight: public Light {
  protected:
    Vector3 direction;  // direction of the light. (0, 0, 0) by default

  public:

    /* constructors */

    DirectionalLight();
    DirectionalLight(Color);
    DirectionalLight(Vector3);
    DirectionalLight(Vector3, Color);

    /* getters */

    Vector3 getDirection();

    /* setters */

    bool setDirection(Vector3);
    bool setDirection(double, double, double);

    float getIntensity(Vector3);
};

class PointLight: public Light {
  protected:
    Vector3 location;   // location of the point light (0, 0, 0) by default

  public:

    /* constructors */

    PointLight();
    PointLight(Color);
    PointLight(Vector3);
    PointLight(Vector3, Color);

    /* getters */

    Vector3 getLocation();

    /* setters */

    bool setLocation(Vector3);
    bool setLocation(double, double, double);

};

#endif
