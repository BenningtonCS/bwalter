#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
  protected:
	float x, y, z;

  public:
	Vector3();
	Vector3(float, float, float);

    /*
        Getters
    */
	float getx();
	float gety();
	float getz();
    void getVector(float*, float*, float*);

    /*
        Setters
    */
	bool setx(float);
	bool sety(float);
	bool setz(float);
    bool setVector(float, float, float);

	// operator overloads
	Vector3 operator+(Vector3);
	Vector3 operator-(Vector3);
    Vector3 operator*(Vector3);
    Vector3 operator/(Vector3);
};

#endif
