#pragma once
#include "Solid.h"
class Prisma : public Solid
{
private:

	float length;
	float height;
	float depth;

public:
	Prisma() :
		Solid(Vector3D(0), Vector3D(0), Color(), Vector3D(0) / 100, Vector3D(0) / 10),
		length(((float)rand() / (RAND_MAX))),
		height(((float)rand() / (RAND_MAX))),
		depth(((float)rand() / (RAND_MAX)))
	{}

	inline float GetLength() const { return this->length; }
	inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }

	inline float GetHeight() const { return this->height; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }

	inline float GetDepth() const { return this->depth; }
	inline void SetDepth(const float& depthToSet) { this->length = depthToSet; }


	void Render();
};


