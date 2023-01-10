#pragma once
#include "Solid.h"

class Arma: public Solid
{
private:

	string nombre;

public:

	Arma() :
		Solid(Vector3D(0), Vector3D(0), Color(), Vector3D(0), Vector3D(0)),
		nombre("name")
	{}

	Arma(string nom):
		nombre(nom)
	{}

	inline string GetNombreArma() const { return this->nombre; }

	inline void SetNombreArma(const string& nombreToSet) { this->nombre = nombreToSet; }
};

