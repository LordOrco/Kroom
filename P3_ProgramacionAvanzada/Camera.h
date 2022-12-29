#pragma once
#include "GL/freeglut.h"
#include "Solid.h"

class Camera : public Solid
{
public:
	Camera(Vector3D positionArgument) :
		Solid(positionArgument)
	{}

	void Render();
};

