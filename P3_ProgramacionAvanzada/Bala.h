#pragma once
#include "Solid.h"
#include "Arma.h"
#include "Sphere.h"

class Bala: public Solid, public Arma, public Sphere
{
private:

	int da�o;

public:

	Bala():
		Solid(Vector3D(0), Vector3D(0), Color(), Vector3D(0), Vector3D(0)),
		Sphere(float(0.0), float(0.0), float(0.0)),
		Arma(string("nombre")),
		da�o(0)
	{}

	inline int GetDa�oBala() const { return this->da�o; }

	inline void SetDa�oBala(const int& da�oToSet) { this->da�o = da�oToSet; }

};

