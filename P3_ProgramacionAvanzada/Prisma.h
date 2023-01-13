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
		Solid(Vector3D(), Vector3D(), Color(255, 0, 0), Vector3D(), Vector3D()),
		length(1),
		height(0.1),
		depth(0.1)
	{}

	inline float GetLength() const { return this->length; }
	inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }

	inline float GetHeight() const { return this->height; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }

	inline float GetDepth() const { return this->depth; }
	inline void SetDepth(const float& depthToSet) { this->length = depthToSet; }


	void Render();
};


