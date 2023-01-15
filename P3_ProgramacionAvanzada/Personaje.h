#pragma once
#include "Model.h"
#include "Camera.h"

class Personaje: public Model
{
private:
	Camera* camara;
	int score;
	int balasMejoradas;

public:

	Personaje(Camera *camaraToSet):
		Model(),
		camara(camaraToSet),
		score(0),
		balasMejoradas(0)
	{}


	inline int GetBalasMejoradas() const { return this->balasMejoradas; }
	inline int GetScore() const { return this->score; }

	inline void SetBalasMejoradas(const int& bulletsToSet) { this->balasMejoradas = bulletsToSet; }
	inline void SetScore(const int& scoreToSet) { this->score = scoreToSet; }

	inline void reset() { this->SetScore(0); this->SetBalasMejoradas(0); };

	void Update(const float& time);
};

