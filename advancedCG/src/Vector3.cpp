#include <stdio.h>

class Vector3 {
  protected:	// instance variables
	float x;	// directional components
	float y;
	float z;	

  public:
	// default constructor
	Vector3() { x=0; y=0; z=0; }
	// alternative constructor
	Vector3(float x, float y, float z) { setVector(x, y, z); }

	// setter methods
	void setVector(float x, float y, float z) { 
		this->x = x;
		this->y = y;
		this->z = z;	
	}
	void setx(float x) { this->x = x; }
	void sety(float y) { this->y = y; }
	void setz(float z) { this->z = z; }

	// getter methods
	void getVector(float *x, float *y, float *z) {
		*x = this->x;
		*y = this->y;
		*z = this->z;
	}
	float getx() { return x; }
	float gety() { return y; }
	float getz() { return z; }

	// operator overloads
	Vector3 operator+(Vector3& v) {
		Vector3 vect;
		vect.setx(getx() + v.getx());
		vect.sety(gety() + v.gety());
		vect.setz(getz() + v.getz());
		return vect;
	}	

	Vector3 operator-(Vector3& v) {
		Vector3 vect;
		vect.setx(getx() - v.getx());
		vect.sety(gety() - v.gety());
		vect.setz(getz() - v.getz());
		return vect;
	}

	// etc. for * and / (and ==, and !=)
};

/*
int main(void) {
	Vector3 v(1, 2, 3);
	Vector3 w(4, 5, 6);
	Vector3 u;

	float x; float y; float z;
	v.getVector(&x, &y, &z);
	printf("%f, %f, %f\n", x, y, z);	// yeah, I should be using std::cout...
	
	u = v + w;
	u.getVector(&x, &y, &z);			
	printf("%f, %f, %f\n", x, y, z);	// but printf() is superior
}
*/
