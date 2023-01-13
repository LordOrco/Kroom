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
		this->camera.move(key);

		break;
	}
}

void Game::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del raton " <<	x << ", " << y << endl;
	if (GetEscenaActual() == 2) {
		this->camera.target(x, y);
	}
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Click:  " << button << endl;
	if (GetEscenaActual() == 2) {
		shoot();
	}
}

void Game::Init() {
	//Colocacion de camara
	this->camera.placeInMenu();

	//Creacion de modelos
	Model* cajaMedicina = new Model();
	Model* cangrejoMalo = new Model();
	Model* escenarioT = new Model();
	Sphere* bala = new Sphere();

	//Cargado de modelos
	ModelLoader* loader = new ModelLoader();

	loader->LoadModel("..\\Assets\\Medicina.obj");
	*cajaMedicina = loader->GetModel();
	loader->Clear();

	loader->SetScale(0.25);
	loader->LoadModel("..\\Assets\\BrazosConPistola.obj");
	personaje.SetTriangles(loader->GetModel().GetTriangles());
	loader->Clear();

	loader->SetScale(1);
	loader->LoadModel("..\\Assets\\CangrejoMalo.obj");
	*cangrejoMalo = loader->GetModel();
	loader->Clear();

	loader->LoadModel("..\\Assets\\EscenarioT.obj");
	*escenarioT = loader->GetModel();
	loader->Clear();

	//Colores de modelos
	cajaMedicina->PaintColor(Color(0.01, 1, 0.01));
	personaje.PaintColor(Color(0.3, 0.3, 0.3));
	cangrejoMalo->PaintColor(Color(1, 0.1, 0.1));
	escenarioT->PaintColor(Color(0.7, 0.8, 0.8));

	//Posiciones de modelos
	escenarioT->SetCoordinateX(0);
	escenarioT->SetCoordinateY(-1);
	escenarioT->SetCoordinateZ(0);

	//Velocidad de modelos
	escenarioT->SetSpeedX(0);
	escenarioT->SetSpeedY(0);
	escenarioT->SetSpeedZ(0);

	//Velocidad de Rotacion de modelos
	escenarioT->SetRotSpeedX(0);
	escenarioT->SetRotSpeedY(0);
	escenarioT->SetRotSpeedZ(0);

	//Rotacion de modelos
	escenarioT->SetRotX(0);
	escenarioT->SetRotY(0);
	escenarioT->SetRotZ(0);

	//Meter los modelos en el vector de objetos para renderizar
	renderizables.push_back(cajaMedicina);
	renderizables.push_back(&personaje);
	renderizables.push_back(cangrejoMalo);
	renderizables.push_back(escenarioT);
	renderizables.push_back(bala);

	//Añadir modelos a escenas
	escenas[2].AddGameObject(&personaje);
	escenas[2].AddGameObject(escenarioT);
	//escenas[2].AddGameObject(cajaMedicina);


	glutWarpPointer(400, 300);
	for (int i = 0; i < escenas.size(); i++) {
		this->escenas[i].Init();
	}
}

void Game::Render() {
	this->camera.Render();
	this->escenas[escenaActual].Render();
}

void Game::Update() {
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMiliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD) {

		this->escenas[escenaActual].Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMiliseconds.count();
	}
}

void Game::shoot() {
	Sphere* bala = new Sphere();
	bala->SetCoordinates(Vector3D(personaje.GetCoordinateX() - 0.025f - float(sin(personaje.GetRotY() * 3.141592654f / 180)), -0.1, 
								  personaje.GetCoordinateZ() - float(cos(personaje.GetRotY() * 3.141592654f / 180))
						));
	bala->SetSpeedX(-float(sin(personaje.GetRotY() * 3.141592654f / 180)));
	bala->SetSpeedZ(-float(cos(personaje.GetRotY() * 3.141592654f / 180)));
	escenas[2].AddGameObject(bala);
}
