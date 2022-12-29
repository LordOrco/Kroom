#include "Game.h"

using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada " << key << endl;
	this->escena.ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del raton " <<	x << ", " << y << endl;
	this->escena.ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Click:  " << button << endl;
	this->escena.ProcessMouseClick(button, state, x, y);
}

void Game::Init() {
	this->escena.Init();
}

void Game::Render() {
	this->escena.Render();
}

void Game::Update() {
	this->escena.Update();
}