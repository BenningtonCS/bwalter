#include <Matrix4.h>


/* constructors */

Matrix4::Matrix4() {
    double identity[4][4] =
            {{1, 0, 0, 0},
             {0, 1, 0, 0},
             {0, 0, 1, 0},
             {0, 0, 0, 1}};
    setMatrix(identity);
}

Matrix4::Matrix4(const double nums[][4]) {
    setMatrix(nums);
}


/* getters */

double (*Matrix4::getMatrix())[4] { return matrix; }


/* setters */

bool Matrix4::setMatrix(const double nums[][4]) {
    for (int row=0; row<4; row++) {
        for (int col=0; col<4; col++) {
            matrix[row][col] = nums[row][col];
        }
    }
    return true;
}


/* class methods */

Matrix4 Matrix4::identity() const {
    double i[4][4] =
        {{1, 0, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 1, 0},
         {0, 0, 0, 1}};

    Matrix4 identity(i);
    return identity;
}

void Matrix4::printMatrix() const {
    for (int i=0; i<4; i++) {
        printf("%.2f, %.2f, %.2f, %.2f\n",
                matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
    }
}

double Matrix4::det3(const double m[][3]) const {
    return m[0][0]*m[1][1]*m[2][2] -
           m[0][0]*m[1][2]*m[2][1] +
           m[0][1]*m[1][2]*m[2][0] -
           m[0][1]*m[1][0]*m[2][2] +
           m[0][2]*m[1][0]*m[2][1] -
           m[0][2]*m[1][1]*m[2][0];
}

double Matrix4::det() const {
    double a[3][3] = {{matrix[1][1], matrix[1][2], matrix[1][3]},
                      {matrix[2][1], matrix[2][2], matrix[2][3]},
                      {matrix[3][1], matrix[3][2], matrix[3][3]}};
    double b[3][3] = {{matrix[1][0], matrix[1][2], matrix[1][3]},
                      {matrix[2][0], matrix[2][2], matrix[2][3]},
                      {matrix[3][0], matrix[3][2], matrix[3][3]}};
    double c[3][3] = {{matrix[1][0], matrix[1][1], matrix[1][3]},
                      {matrix[2][0], matrix[2][1], matrix[2][3]},
                      {matrix[3][0], matrix[3][1], matrix[3][3]}};
    double d[3][3] = {{matrix[1][0], matrix[1][1], matrix[1][1]},
                      {matrix[2][0], matrix[2][1], matrix[2][1]},
                      {matrix[3][0], matrix[3][1], matrix[3][1]}};

    return matrix[0][0]*det3(a) - matrix[0][1]*det3(b) +
           matrix[0][2]*det3(c) - matrix[0][3]*det3(d);
}

Matrix4 Matrix4::getTranspose() const {
    double m[4][4] =
        {{matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0]},
         {matrix[0][1], matrix[1][1], matrix[2][1], matrix[3][1]},
         {matrix[0][2], matrix[1][2], matrix[2][2], matrix[3][2]},
         {matrix[0][3], matrix[1][3], matrix[2][3], matrix[3][3]}};

    Matrix4 transpose(m);
    return transpose;
}

Vector3 Matrix4::transformPoint(const Vector3& p) const {
    double x, y, z;
    x = p.getx(); y = p.gety(); z = p.getz();
    Vector3 result(
        matrix[0][0]*x + matrix[0][1]*y + matrix[0][2]*z + matrix[0][3]*1,
        matrix[1][0]*x + matrix[1][1]*y + matrix[1][2]*z + matrix[1][3]*1,
        matrix[2][0]*x + matrix[2][1]*y + matrix[2][2]*z + matrix[2][3]*1);
    return result;
}

Vector3 Matrix4::transformVector(const Vector3& v) const {
    double x, y, z;
    x = v.getx(); y = v.gety(); z = v.getz();
    Vector3 result(
        matrix[0][0]*x + matrix[0][1]*y + matrix[0][2]*z,
        matrix[1][0]*x + matrix[1][1]*y + matrix[1][2]*z,
        matrix[2][0]*x + matrix[2][1]*y + matrix[2][2]*z);
    return result;
}

Ray3 Matrix4::transformRay(const Ray3& r) const {
    Vector3 origin = transformPoint(r.getOrigin());
    Vector3 direction = transformVector(r.getDirection());
    Ray3 result(origin, direction);
    return result;
}

Matrix4 Matrix4::getScaleBy(const Vector3& v) const {
    double m[4][4] =
        {{v.getx(), 0, 0, 0},
         {0, v.gety(), 0, 0},
         {0, 0, v.getz(), 0},
         {0, 0, 0, 1}};

    Matrix4 scale(m);
    return scale;
}

Matrix4 Matrix4::getTranslateBy(const Vector3& v) const {
    double m[4][4] =
        {{1, 0, 0, v.getx()},
         {0, 1, 0, v.gety()},
         {0, 0, 1, v.getz()},
         {0, 0, 0, 1}};

    Matrix4 translate(m);
    return translate;
}

Matrix4 Matrix4::getRotationX(const float degrees) const {
    double m[4][4] =
        {{1, 0, 0,0 },
         {0, cos(degrees), -sin(degrees), 0},
         {0, sin(degrees), cos(degrees), 0},
         {0, 0, 0, 1}};

    Matrix4 rot(m);
    return rot;
}

Matrix4 Matrix4::getRotationY(const float degrees) const {
    double m[4][4] =
        {{cos(degrees), 0, sin(degrees), 0},
         {0, 1, 0, 0},
         {-sin(degrees), 0, cos(degrees), 0},
         {0, 0, 0, 1}};

    Matrix4 rot(m);
    return rot;
}

Matrix4 Matrix4::getRotationZ(const float degrees) const {
    double m[4][4] =
        {{cos(degrees), -sin(degrees), 0, 0},
         {sin(degrees), cos(degrees), 0, 0},
         {0, 0, 1, 0},
         {0, 0, 0, 1}};

    Matrix4 rot(m);
    return rot;
}

/* operator overloads */

Matrix4 Matrix4::operator+(Matrix4 m) const {
    double array[4][4];
    for (int row=0; row<4; row++) {
        for (int col=0; col<4; col++) {
            array[row][col] = matrix[row][col] + (m.getMatrix())[row][col];
        }
    }
    Matrix4 result(array);
    return result;
}

Matrix4 Matrix4::operator-(Matrix4 m) const {
    double array[4][4];
    for (int row=0; row<4; row++) {
        for (int col=0; col<4; col++) {
            array[row][col] = matrix[row][col] - (m.getMatrix())[row][col];
        }
    }
    Matrix4 result(array);
    return result;
}

Matrix4 Matrix4::operator*(Matrix4 m) const {
    double array[4][4];
    for (int row=0; row<4; row++) {
        for (int col=0; col<4; col++) {
            double val = 0;
            for (int i=0; i<4; i++) {
                val += matrix[row][i] * (m.getMatrix())[i][col];
            }
            array[row][col] = val;
        }
    }
    Matrix4 result(array);
    return result;
}

Matrix4 Matrix4::operator*(double s) const {
    double array[4][4];
    for (int row=0; row<4; row++) {
        for (int col=0; col<4; col++) {
            array[row][col] = matrix[row][col] * s;
        }
    }
    Matrix4 result(array);
    return result;
}

Matrix4 Matrix4::operator/(double s) const {
    double array[4][4];
    for (int row=0; row<4; row++) {
        for (int col=0; col<4; col++) {
            array[row][col] = matrix[row][col] / s;
        }
    }
    Matrix4 result(array);
    return result;
}
