#include "Vector3D.h"


Vector3D Vector3D::suma(Vector3D b) {
    Vector3D resultado;
    resultado.x = x + b.x;
    resultado.y = y + b.y;
    resultado.z = z + b.z;

    return resultado;
}

Vector3D Vector3D::resta(Vector3D b) {
    Vector3D resultado;
    resultado.x = x - b.x;
    resultado.y = y - b.y;
    resultado.z = z - b.z;

    return resultado;
}

float Vector3D::productoEscalar(Vector3D b) {
    float resultado;
    resultado = x * b.x + y * b.y + z * b.z;
    return resultado;
}

Vector3D Vector3D::productoPorEscalar(float b) {
    Vector3D resultado;
    resultado.x = b * x;
    resultado.y = b * y;
    resultado.z = b * z;
    return resultado;
}

Vector3D Vector3D::productoVectorial(Vector3D b) {
    Vector3D resultado;
    resultado.x = y * b.z - z * b.y;
    resultado.y = -1 * (x * b.z - z * b.x);
    resultado.z = x * b.y - y * b.x;
    return resultado;
}

float Vector3D::modulo() {
    float resultado;
    resultado = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return resultado;
}

Vector3D Vector3D::operator+(Vector3D b) {
    return suma(b);
}

Vector3D Vector3D::operator-(Vector3D b) {
    return resta(b);
}

Vector3D Vector3D::operator*(float b) {
    return productoPorEscalar(b);
}

float Vector3D::operator*(Vector3D b) {
    return productoEscalar(b);
}

Vector3D Vector3D::operator/(float b) {
    Vector3D resultado;
    resultado.x = x / b;
    resultado.y = y / b;
    resultado.z = z / b;
    return resultado;
}

void Vector3D::imprimirVector() {
    cout << "(" << x << ", " << y << ", " << z << ")\n";
}