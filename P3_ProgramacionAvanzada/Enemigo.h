#pragma once
#include "Model.h"

class Enemigo: public Model
{
private:
	int hp;
	Model* toFollow;

public:

	Enemigo(Vector3D coordenadas, Model* modelToFollow) :
		Model(),
		toFollow(modelToFollow),
		hp(500)
	{}

	inline int GetHP() const { return this->hp; }
	inline Model* GetToFollow() const { return this->toFollow; }

	inline void SetHP(const int& HPToSet) { this->hp = HPToSet; }

	void Update(const float& time);
};

