#pragma once
#include "Solid.h"
#include "Model.h"
#include "Sphere.h"

class ObjetoRenderizable:public Solid
{
private:

	Model renderizable;
	Sphere bala;

public:

	inline Model GetObjetoRenderizable() const { return this->renderizable; }
	inline Sphere GetBalaRenderizable() const { return this->bala; }

	inline void SetObjetoRenderizable(const Model& modelToSet) { this->renderizable = modelToSet; }
	inline void SetBalaRenderizable(const Sphere& balaToSet) { this->bala = balaToSet; }

	void Render();

};

