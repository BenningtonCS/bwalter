#ifndef MATRICES_H
#define MATRICES_H

#include <stdio.h>

#include <Vector3.h>
#include <Ray3.h>


class Matrix4 {
  protected:
    double matrix[4][4];
    double inverse[4][4];


    /* class methods */

    Matrix4 identity() const;           // get the 4x4 identity matrix
    double det3(const double [][3]) const; // 3x3 matrix determinant

  public:

    /* constructors */

    Matrix4();
    Matrix4(const double [][4]);


    /* getters */

    double (*getMatrix())[4];
    double (*getInverse())[4];


    /* setters */

    bool setMatrix(const double [][4]);


    /* class methods */

    void printMatrix() const;
    double det() const;

    Vector3 transformPoint(const Vector3&) const;
    Vector3 transformVector(const Vector3&) const;
    Ray3 transformRay(const Ray3&) const;

    Matrix4 getRotationX(const float) const;
    Matrix4 getRotationY(const float) const;
    Matrix4 getRotationZ(const float) const;


    /* operator overloads */

    Matrix4 operator+(Matrix4) const;   // matrix addition
    Matrix4 operator-(Matrix4) const;   // matrix subtraction
    Matrix4 operator*(Matrix4) const;   // matrix multiplication
    Matrix4 operator*(double) const;    // scalar multiplication
    Matrix4 operator/(double) const;    // scalar division
};

#endif
