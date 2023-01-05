#pragma once
#include "Solid.h"
#include "Arma.h"
#include "Sphere.h"

class Bala: public Solid, public Arma, public Sphere
{
private:

	int daño;

public:

	Bala():
		Solid(Vector3D(0), Vector3D(0), Color(), Vector3D(0), Vector3D(0)),
		Sphere(float(0.0), float(0.0), float(0.0)),
		Arma(string("nombre")),
		daño(0)
	{}

	inline int GetDañoBala() const { return this->daño; }

	inline void SetDañoBala(const int& dañoToSet) { this->daño = dañoToSet; }

};

