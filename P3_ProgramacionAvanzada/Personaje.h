#pragma once
#include "Model.h"
#include "Camera.h"
#include "ObjetoRenderizable.h"

class Personaje: public Model
{
private:
	Camera* camara;
	int hp;
	int score;
	int ammo;

public:

	Personaje(Camera *camaraToSet):
		Model(),
		camara(camaraToSet),
		hp(500),
		score(0),
		ammo(120)
	{}


	inline int GetHP() const { return this->hp; }
	inline int GetScore() const { return this->score; }
	inline int GetAmmo() const { return this->ammo; }

	inline void SetHP(const int& HPToSet) { this->hp = HPToSet; }
	inline void SetScore(const int& scoreToSet) { this->score = scoreToSet; }
	inline void SetAmmo(const int& ammoToSet) { this->ammo = ammoToSet; }

	void Update(const float& time);
};

