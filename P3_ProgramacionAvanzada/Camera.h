#pragma once
#include "GL/freeglut.h"
#include "Solid.h"
#include "Text.h"
#include "Prisma.h"

class Camera : public Solid
{
private:
	int lastx;
	int lasty;

public:
	Camera(Vector3D positionArgument) :
		Solid(positionArgument),
		lastx(400),
		lasty(300)
	{
		this->SetOrientation(Vector3D(0, 0, 0));
	}

	void Render();

	void move(unsigned char key);
	void target(int x, int y);

	void placeInPlayGround();
	void placeInMenu();
};

