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
	vector <Scene> escenas;
	int escenaActual;

	Scene escenaPruebas;
	Scene menuPrincipal;
	Scene juego;
	Scene resultados;

public:

	Game():
		escenaActual(0),
		escenaPruebas(0),
		menuPrincipal(1),
		juego(2),
		resultados(3)
	{
		escenas.push_back(escenaPruebas);
		escenas.push_back(menuPrincipal);
		escenas.push_back(juego);
		escenas.push_back(resultados);
	}

	~Game(){ }

	inline Scene GetScene() const { return this->escenas[escenaActual]; }
	inline int GetEscenaActual() { return this->escenaActual; }

	inline void SetEscenaActual(int escenaToSet) { this->escenaActual = escenaToSet; }

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

};

