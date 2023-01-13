#pragma once
#include "ObjetoRenderizable.h"

class Medicina
{
private:

	int vida_a�adida;

public:

	Medicina():
		vida_a�adida((int)rand() % 10)
	{}

	inline int GetVida() const { return this->vida_a�adida; }

	inline void SetVida(const int& vidaToSet) { this->vida_a�adida = vidaToSet; }
};

