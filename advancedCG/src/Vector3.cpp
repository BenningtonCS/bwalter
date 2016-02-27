#include <Vector3.h>

// default constructor
Vector3::Vector3() { x=0; y=0; z=0; }
// alternative constructor
Vector3::Vector3(float x, float y, float z) { setVector(x, y, z); }

// setter methods
void Vector3::setVector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
void Vector3::setx(float x) { this->x = x; }
void Vector3::sety(float y) { this->y = y; }
void Vector3::setz(float z) { this->z = z; }

// getter methods
void Vector3::getVector(float* x, float* y, float* z) {
	*x = this->x;
	*y = this->y;
	*z = this->z;
}
float Vector3::getx() { return x; }
float Vector3::gety() { return y; }
float Vector3::getz() { return z; }

// operator overloads
Vector3 Vector3::operator+(Vector3 v) {
	Vector3 vector;
	vector.setx(getx() + v.getx());
	vector.sety(gety() + v.gety());
	vector.setz(getz() + v.getz());
	return vector;
}

Vector3 Vector3::operator-(Vector3 v) {
	Vector3 vector;
	vector.setx(getx() - v.getx());
	vector.sety(gety() - v.gety());
	vector.setz(getz() - v.getz());
	return vector;
}

Vector3 Vector3::operator*(Vector3 v) {
	Vector3 vector;
	vector.setx(getx() * v.getx());
	vector.sety(gety() * v.gety());
	vector.setz(getz() * v.getz());
	return vector;
}

Vector3 Vector3::operator/(Vector3 v) {
	Vector3 vector;
	vector.setx(getx() / v.getx());
	vector.sety(gety() / v.gety());
	vector.setz(getz() / v.getz());
	return vector;
}
