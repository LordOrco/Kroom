#pragma once
#include "GL/freeglut.h"
#include "Solid.h"
#include "Text.h"

class Camera : public Solid
{
private:
	int lastx;
	int lastz;

public:
	Camera(Vector3D<float> positionArgument) :
		Solid(positionArgument),
		lastx(0),
		lastz(0)
	{
		this->SetOrientation(Vector3D<float>(0, 0, 0));
	}

	void Render();

	void move(unsigned char key);
	void target(int x, int y);

	inline int GetLastX() { return this->lastx; };
	inline int GetLastZ() { return this->lastz; };

	void placeInMenu();
};

