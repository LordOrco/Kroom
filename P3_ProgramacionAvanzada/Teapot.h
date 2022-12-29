#pragma once
#include "Solid.h"

class Teapot : public Solid
{
private: 

	float size;

public: 
	Teapot(): 
		Solid(Vector3D(0), Vector3D(0), Color(), Vector3D(0)/100, Vector3D(0)/10),
		size(((float)rand() / (RAND_MAX)))
	{}

	inline float GetSize() const { return this->size; }
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();
};

