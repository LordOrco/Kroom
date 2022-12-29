#pragma once
#include "Solid.h"

class Cube : public Solid
{

private:
	Vector3D coordinates;
	Vector3D orientation;
	Color color;

	float size;

public:
	Cube(): 
		Solid(Vector3D(0), Vector3D(0), Color(), Vector3D(0) / 100, Vector3D(0) / 10),
		size(((float)rand() / (RAND_MAX))) 
	{}

	inline float GetSize() const { return this->size; }
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();
};

