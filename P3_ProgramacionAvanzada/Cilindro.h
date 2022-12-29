#pragma once
#include "Solid.h"

class Cilindro : public Solid
{
private:
	float lowerRadius;
	float upperRadius;
	float height;
	float slices;
	float stacks;

public:
	Cilindro() :
		Solid(Vector3D(0.0f, 0.0f, 0.0f), Vector3D(0.0f, 90.0f, 0.4f), Color(), Vector3D(-0.002f, 0.001f, 0.0f), Vector3D(0.01f, 0.0f, 0.0f)),
		lowerRadius(0.2),
		upperRadius(0.2),
		height(1),
		slices(40),
		stacks(40)
	{}

	inline float GetLowerRadius() const { return this->lowerRadius; }
	inline void SetLowerRadius(const float& lowerRadiusToSet) { this->lowerRadius = lowerRadiusToSet; }

	inline float GetUpperRadius() const { return this->upperRadius; }
	inline void SetUpperRadius(const float& upperRadiusToSet) { this->upperRadius = upperRadiusToSet; }

	inline float GetHeight() const { return this->height; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }

	inline float GetSlices() const { return this->slices; }
	inline void SetSlices(const float& slicesToSet) { this->slices = slicesToSet; }

	inline float GetStacks() const { return this->stacks; }
	inline void SetStacks(const float& stacksToSet) { this->stacks = stacksToSet; }


	void Render();

};

