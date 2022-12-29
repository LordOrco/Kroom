#pragma once
#include <iostream>
#include <vector>
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Prisma.h"
#include "Toroide.h"
#include "Cilindro.h"
#include "Scene.h"

using namespace std;

class Game
{
private:
	Scene escena;

public:

	Game() {}

	~Game(){ }

	inline Scene GetScene() const { return this->escena; }

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

};

