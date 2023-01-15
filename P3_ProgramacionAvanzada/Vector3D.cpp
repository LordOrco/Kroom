#include "Vector3D.h"


Vector3D<float> Vector3D<float>::suma(Vector3D<float> b) {
    Vector3D<float> resultado;
    resultado.x = x + b.x;
    resultado.y = y + b.y;
    resultado.z = z + b.z;

    return resultado;
}

Vector3D<float> Vector3D<float>::resta(Vector3D<float> b) {
    Vector3D<float> resultado;
    resultado.x = x - b.x;
    resultado.y = y - b.y;
    resultado.z = z - b.z;

    return resultado;
}

float Vector3D<float>::productoEscalar(Vector3D<float> b) {
    float resultado;
    resultado = x * b.x + y * b.y + z * b.z;
    return resultado;
}

Vector3D<float> Vector3D<float>::productoPorEscalar(float b) {
    Vector3D<float> resultado;
    resultado.x = b * x;
    resultado.y = b * y;
    resultado.z = b * z;
    return resultado;
}

Vector3D<float> Vector3D<float>::productoVectorial(Vector3D<float> b) {
    Vector3D<float> resultado;
    resultado.x = y * b.z - z * b.y;
    resultado.y = -1 * (x * b.z - z * b.x);
    resultado.z = x * b.y - y * b.x;
    return resultado;
}

float Vector3D<float>::modulo() {
    float resultado;
    resultado = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return resultado;
}

Vector3D<float> Vector3D<float>::operator+(Vector3D b) {
    return suma(b);
}

Vector3D<float> Vector3D<float>::operator-(Vector3D<float> b) {
    return resta(b);
}

Vector3D<float> Vector3D<float>::operator*(float b) {
    return productoPorEscalar(b);
}

float Vector3D<float>::operator*(Vector3D<float> b) {
    return productoEscalar(b);
}

Vector3D<float> Vector3D<float>::operator/(float b) {
    Vector3D<float> resultado;
    resultado.x = x / b;
    resultado.y = y / b;
    resultado.z = z / b;
    return resultado;
}

void Vector3D<float>::imprimirVector() {
    cout << "(" << x << ", " << y << ", " << z << ")\n";
}