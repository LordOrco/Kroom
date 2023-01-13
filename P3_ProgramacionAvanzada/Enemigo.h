#pragma once
#include "Model.h"

class Enemigo: public Model
{
private:
	int hp;

public:

	Enemigo(Vector3D coordenadas) :
		Model(),
		hp(500)
	{}

	inline int GetHP() const { return this->hp; }
	inline void SetHP(const int& HPToSet) { this->hp = HPToSet; }

	void Update(const float& time);
};

