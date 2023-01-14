#pragma once
#include <iostream>
#include <vector>
#include "Cube.h"
#include "Sphere.h"
#include "Scene.h"
#include "Personaje.h"
#include "Enemigo.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

class Game
{
private:
	//Control de movimiento
	bool wPressed;
	bool aPressed;
	bool sPressed;
	bool dPressed;

	Camera camera;
	Personaje personaje;
	vector <Model*> renderizables;

	//Control de escenas
	int boundaryRadius;

	vector <Scene> escenas;

	int escenaActual;

	Scene escenaPruebas;
	Scene menuPrincipal;
	Scene juego;
	Scene resultados;

	//control fps
	const double TIME_INCREMENT = 1.0 / 30.0; //tiempo juego
	const long UPDATE_PERIOD = 1000 / 30.0; //tiempo real
	
	milliseconds initialMiliseconds;
	long lastUpdatedTime;

public:

	Game() :
		escenaActual(1),
		camera(Vector3D(0, 0, 0)),
		personaje(&camera),
		escenaPruebas(),
		menuPrincipal(),
		juego(),
		resultados(),

		initialMiliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())),
		lastUpdatedTime(0),

		wPressed(false),
		aPressed(false),
		sPressed(false),
		dPressed(false),

		boundaryRadius(35)

	{
		escenas.push_back(escenaPruebas);
		escenas.push_back(menuPrincipal);
		escenas.push_back(juego);
		escenas.push_back(resultados);
	}

	~Game(){ }

	inline Scene GetScene() const { return this->escenas[escenaActual]; }
	inline Camera GetCamera() { return this->camera; }
	inline int GetEscenaActual() { return this->escenaActual; }
	inline float GetBoundaryRadius() const { return this->boundaryRadius; }

	inline void SetBoundaryRadius(const float& boundaryToSet) { this->boundaryRadius = boundaryToSet; }
	inline void SetEscenaActual(int escenaToSet) { this->escenaActual = escenaToSet; }

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

	void shoot();
	void step();
	void spawnEnemy();
	void movimientoJugador();
	void collisions();
	void checkBoundary();
	void newGame();
};

