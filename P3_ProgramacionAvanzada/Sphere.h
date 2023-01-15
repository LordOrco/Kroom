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
		Solid(Vector3D(), Vector3D(), Color(0, 0, 1), Vector3D(), Vector3D()),
		radius(0.025),
		slices(20),
		slacks(20) 
	{}

	Sphere(Vector3D pos, Vector3D speed) :
		Solid(pos, Vector3D(), Color(), speed, Vector3D()),
		radius(0.025),
		slices(20),
		slacks(20)
	{}


	Sphere(float radiusToSet, float slicesToSet, float slackToSet):
		radius(radiusToSet),
		slices(slicesToSet),
		slacks(slackToSet)
	{}

	inline float GetRadius() const { return this->radius; }
	inline float GetSlices() const { return this->slices; }
	inline float GetSlacks() const { return this->slacks; }

	inline void SetRadius(const float& radiusToSet) { this->radius = radiusToSet; }
	inline void SetSlices(const float& slicesToSet) { this->slices = slicesToSet; }
	inline void SetSlacks(const float& slacksToSet) { this->slacks = slacksToSet; }
	

	void Render();
};

