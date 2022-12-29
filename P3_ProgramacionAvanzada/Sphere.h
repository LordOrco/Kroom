#pragma once
#include "Solid.h"

class Sphere : public Solid
{
private:

	float radius;
	float slices;
	float slacks;

public:
	Sphere():
		Solid(Vector3D(0), Vector3D(0), Color(), Vector3D(0) / 100, Vector3D(0) / 10),
		radius(((float)rand() / (RAND_MAX))),
		slices(20),
		slacks(20) 
	{}

	inline float GetRadius() const { return this->radius; }
	inline float GetSlices() const { return this->slices; }
	inline float GetSlacks() const { return this->slacks; }

	inline void SetRadius(const float& radiusToSet) { this->radius = radiusToSet; }
	inline void SetSlices(const float& slicesToSet) { this->slices = slicesToSet; }
	inline void SetSlacks(const float& slacksToSet) { this->slacks = slacksToSet; }
	

	void Render();
};

