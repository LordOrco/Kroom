#pragma once
#include "Model.h"
#include "Camera.h"
#include "ObjetoRenderizable.h"

class Personaje: public Model
{
private:
	Camera* camara;
	int score;

public:

	Personaje(Camera *camaraToSet):
		Model(),
		camara(camaraToSet),
		score(0)
	{}


	inline int GetScore() const { return this->score; }

	inline void SetScore(const int& scoreToSet) { this->score = scoreToSet; }
	inline void reset() { this->SetScore(0); };

	void Update(const float& time);
};

