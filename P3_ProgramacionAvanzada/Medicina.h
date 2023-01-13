#pragma once
#include "ObjetoRenderizable.h"

class Medicina
{
private:

	int vida_añadida;

public:

	Medicina():
		vida_añadida((int)rand() % 10)
	{}

	inline int GetVida() const { return this->vida_añadida; }

	inline void SetVida(const int& vidaToSet) { this->vida_añadida = vidaToSet; }
};

