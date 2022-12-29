#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

class Vector3D
{
private:
    float x;
    float y;
    float z;

public:

    Vector3D() :
        x(0),
        y(0),
        z(0) {}

    Vector3D(bool e) :
        x((float)rand() / (RAND_MAX)),
        y((float)rand() / (RAND_MAX)),
        z((float)rand() / (RAND_MAX)) {}

    Vector3D(float xToSet, float yToSet, float zToSet) :
        x(xToSet),
        y(yToSet),
        z(zToSet) {}

    inline float GetX() const { return this->x; }
    inline float GetY() const { return this->y; }
    inline float GetZ() const { return this->z; }

    inline void SetX(const float& xToSet) { this->x = xToSet; }
    inline void SetY(const float& yToSet) { this->y = yToSet; }
    inline void SetZ(const float& zToSet) { this->z = zToSet; }

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

