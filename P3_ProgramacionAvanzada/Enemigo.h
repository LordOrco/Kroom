#pragma once
#include "Model.h"

class Enemigo: public Model
{
private:
	int hp;
	Model* toFollow;
	float lastX;
	float lastZ;

public:

	Enemigo(Vector3D coordenadas, Model* modelToFollow) :
		Model(coordenadas),
		toFollow(modelToFollow),
		hp(4),
		lastX(coordenadas.GetX()),
		lastZ(coordenadas.GetZ())
	{}

	inline int GetHP() const { return this->hp; }
	inline Model* GetToFollow() const { return this->toFollow; }

	inline void SetHP(const int& HPToSet) { this->hp = HPToSet; }

	void Update(const float& time);
};

