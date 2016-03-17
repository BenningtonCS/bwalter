#ifndef LIGHTS_H
#define LIGHTS_H

#include <Color.h>
#include <Objects.h>
#include <Vector3.h>

class Light {
  protected:
    Color color;        // Color of the light. White by default

    bool setColor();

  public:

    /* getters */

    Color getColor() const;

    /* setters */

    bool setColor(const Color&);
    bool setColor(const float, const float, const float);               // rgb
    bool setColor(const float, const float, const float, const float);  // rgba


    /* class methods */

    virtual float getIntensity(const Vector3&, const Object&) const;
};

class DirectionalLight: public Light {
  protected:
    Vector3 direction;  // direction of the light. (0, 0, 0) by default

  private:
    bool setDirection();

  public:

    /* constructors */

    DirectionalLight();
    DirectionalLight(const Color&);
    DirectionalLight(const Vector3&);
    DirectionalLight(const Vector3&, const Color&);

    /* getters */

    Vector3 getDirection() const;

    /* setters */

    bool setDirection(const Vector3&);
    bool setDirection(const double, const double, const double);

    float getIntensity(Vector3, Object*) const;
};

class PointLight: public Light {
  protected:
    Vector3 location;   // location of the point light (0, 0, 0) by default

    bool setLocation();

  public:

    /* constructors */

    PointLight();
    PointLight(const Color&);
    PointLight(const Vector3&);
    PointLight(const Vector3&, const Color&);

    /* getters */

    Vector3 getLocation() const;

    /* setters */

    bool setLocation(const Vector3&);
    bool setLocation(const double, const double, const double);

};

#endif
