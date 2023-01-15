#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

template <class var>
class Vector3D
{
private:
    var x;
    var y;
    var z;

public:

    Vector3D() :
        x(0),
        y(0),
        z(0) {}

    Vector3D(var xToSet, var yToSet, var zToSet) :
        x(xToSet),
        y(yToSet),
        z(zToSet) {}

    inline var GetX() const { return this->x; }
    inline var GetY() const { return this->y; }
    inline var GetZ() const { return this->z; }

    inline void SetX(const var& xToSet) { this->x = xToSet; }
    inline void SetY(const var& yToSet) { this->y = yToSet; }
    inline void SetZ(const var& zToSet) { this->z = zToSet; }

    Vector3D suma(Vector3D b);
    Vector3D resta(Vector3D b);
    float productoEscalar(Vector3D b);
    Vector3D productoPorEscalar(float b);
    Vector3D productoVectorial(Vector3D b);
    float modulo();
    Vector3D operator+(Vector3D b);
    Vector3D operator-(Vector3D b);
    Vector3D operator/(float b);
    float operator*(Vector3D b);
    Vector3D operator*(float b);
    void imprimirVector();

};

