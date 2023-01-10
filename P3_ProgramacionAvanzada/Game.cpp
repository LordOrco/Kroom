#include "Game.h"

using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada " << key << endl;
	switch (escenaActual) {
	case 0:
		escenaActual++;
		break;
	case 1:
		switch (key) {
		case '1':
			SetEscenaActual(2);
			break;
		case '2':
			SetEscenaActual(3);
			break;
		}
		break;

	case 2:
		this->escenas[escenaActual].ProcessKeyPressed(key, px, py);
		break;
	}
}

void Game::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del raton " <<	x << ", " << y << endl;
	this->escenas[escenaActual].ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Click:  " << button << endl;
	this->escenas[escenaActual].ProcessMouseClick(button, state, x, y);
}

void Game::Init() {
	glutWarpPointer(400, 300);
	for (int i = 0; i < escenas.size(); i++) {
		this->escenas[i].Init();
	}
}

void Game::Render() {
	this->escenas[escenaActual].Render();
}

void Game::Update() {
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMiliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD) {
		this->escenas[escenaActual].Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMiliseconds.count();
	}
}