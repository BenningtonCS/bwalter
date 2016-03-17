#include <Vector3.h>

/* constructors */

Vector3::Vector3() { setVector(0, 0, 0); }
Vector3::Vector3(double X, double Y, double Z) { setVector(X, Y, Z); }


/* getters */

double Vector3::getx() const { return x; }
double Vector3::gety() const { return y; }
double Vector3::getz() const { return z; }
void Vector3::getVector(double* X, double* Y, double* Z) const {
    *X = x; *Y = y; *Z = z;
}


/* setters */

bool Vector3::setx(double X) { x = X; return true; }
bool Vector3::sety(double Y) { y = Y; return true; }
bool Vector3::setz(double Z) { z = Z; return true; }
bool Vector3::setVector(double X, double Y, double Z) {
    if (setx(X) && sety(Y) && setz(Z)) return true;
    return false;
}


/* class methods */

double Vector3::getMagnitude() const {
    double magnitude = sqrt(getMagnitudeSquared());
    return magnitude;
}

double Vector3::getMagnitudeSquared() const {
    double magnitude = pow(x, 2) + pow(y, 2) + pow(z, 2);
    return magnitude;
}

Vector3 Vector3::makeUnitVector() const {
    double magnitude = getMagnitude();

    Vector3 vector;
    vector.setx(getx()/magnitude);
    vector.sety(gety()/magnitude);
    vector.setz(getz()/magnitude);

    return vector;
}

void Vector3::printVector() const {
    printf("(%.5f, %.5f, %.5f)\n", x, y, z);
}

/* operator overloads */

Vector3 Vector3::operator+(Vector3 v) const {
	Vector3 vector;
	vector.setx(getx() + v.getx());
	vector.sety(gety() + v.gety());
	vector.setz(getz() + v.getz());
	return vector;
}

Vector3 Vector3::operator-(Vector3 v) const {
	Vector3 vector;
	vector.setx(getx() - v.getx());
	vector.sety(gety() - v.gety());
	vector.setz(getz() - v.getz());
	return vector;
}

Vector3 Vector3::operator/(double value) const {
    Vector3 result(getx()/value, gety()/value, getz()/value);
    return result;
}

Vector3 Vector3::operator*(double value) const {
    Vector3 result(getx()*value, gety()*value, getz()*value);
    return result;
}

double Vector3::operator*(Vector3 v) const {
    double totalx = getx() * v.getx();
    double totaly = gety() * v.gety();
    double totalz = getz() * v.getz();
    return totalx + totaly + totalz;
}

bool Vector3::operator==(Vector3 v) const {
    if (getx() == v.getx() &&
        gety() == v.gety() &&
        getz() == v.getz())
        return true;

    return false;
}

bool Vector3::operator!=(Vector3 v) const {
    if (getx() != v.getx() &&
        gety() != v.gety() &&
        getz() != v.getz())
        return true;

    return false;
}
