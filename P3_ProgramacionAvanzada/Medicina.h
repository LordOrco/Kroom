#pragma once
#include "Solid.h"

class Medicina: public Solid
{
private:

	int vida_añadida;

public:

	Medicina():
		Solid(Vector3D(), Vector3D(), Color()),
		vida_añadida((int)rand() % 10) //asumimos que el máximo de vida del personaje es 10
	{}

	inline int GetVida() const { return this->vida_añadida; }

	inline void SetVida(const int& vidaToSet) { this->vida_añadida = vidaToSet; }
};

