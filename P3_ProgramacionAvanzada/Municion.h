#pragma once
#include "Solid.h"

class Municion: public Solid
{
private:

	int num_balas;
	int tipo_bala;

public:

	Municion() :
		Solid(Vector3D(0), Vector3D(0), Color(0)),
		num_balas((int)rand() % 40), //he puesto 40 como máximo de balas posibles de encontrarte
		tipo_bala((int)rand() % 3) //de momento asumimos que hay 3 tipos de balas
	{}

	inline int GetBalasEscena() const { return this->num_balas; }
	inline int GetTipoBalasEscena() const { return this->tipo_bala; }

	inline void SetBalasEscena(const int& balasToSet) { this->num_balas = balasToSet; }
	inline void SetTipoBalasEscena(const int& tipoToSet) { this->tipo_bala = tipoToSet; }

};

