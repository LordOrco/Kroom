#pragma once
#include "Solid.h"

class Toroide : public Solid
{
private: 
	float internalRadius;
	float externalRadius;
	float faces;
	float rings;

public:
	Toroide() :
		Solid(Vector3D(0), Vector3D(0), Color(), Vector3D(0) / 100, Vector3D(0) / 10),
		internalRadius(((float)rand() / (RAND_MAX))),
		externalRadius(((float)rand() / (RAND_MAX))),
		faces(40),
		rings(40)
	{}

	inline float GetInternalRadius() const { return this->internalRadius; }
	inline void SetInternalRadius(const float& internalRadiusToSet) { this->internalRadius = internalRadiusToSet; }

	inline float GetExternalRadius() const { return this->externalRadius; }
	inline void SetExternalRadius(const float& externalRadiusToSet) { this->externalRadius = externalRadiusToSet; }

	inline float GetFaces() const { return this->faces; }
	inline void SetFaces(const float& facesToSet) { this->faces = facesToSet; }

	inline float GetRings() const { return this->rings; }
	inline void SetRings(const float& ringsToSet) { this->rings = ringsToSet; }


	void Render();
};

