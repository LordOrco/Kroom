#pragma once
#include "Model.h"

class BalaPowerUp: public Model
{
private:

	int balasMejoradas;
	bool activa;

public:

	BalaPowerUp(Vector3D<float> coordenadas):
		Model(coordenadas),
		activa(true),
		balasMejoradas(10)
	{}

	inline int GetBalasMejoradas() const { return this->balasMejoradas; }
	inline bool GetActiva() const { return this->activa; }

	inline void SetBalasMejoradas(const int& balasToSet) { this->balasMejoradas = balasToSet; }
	inline void SetActiva(const bool& pactiva) { this->activa = pactiva; }
};

