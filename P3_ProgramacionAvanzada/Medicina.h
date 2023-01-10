#pragma once
#include "Solid.h"

class Medicina: public Solid
{
private:

	int vida_a�adida;

public:

	Medicina():
		Solid(Vector3D(), Vector3D(), Color()),
		vida_a�adida((int)rand() % 10) //asumimos que el m�ximo de vida del personaje es 10
	{}

	inline int GetVida() const { return this->vida_a�adida; }

	inline void SetVida(const int& vidaToSet) { this->vida_a�adida = vidaToSet; }
};

