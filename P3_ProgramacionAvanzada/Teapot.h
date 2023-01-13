#pragma once
#include "Solid.h"

class Teapot : public Solid
{
private: 

	float size;

public: 
	Teapot(): 
		Solid(Vector3D(), Vector3D(), Color(), Vector3D(), Vector3D()),
		size(((float)rand() / (RAND_MAX)))
	{}

	inline float GetSize() const { return this->size; }
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();
};

