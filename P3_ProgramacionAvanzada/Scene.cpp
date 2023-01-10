#include "Scene.h"

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada " << key << endl;
	this->camera.move(key);
}

void Scene::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del raton " << x << ", " << y << endl;
	if (this->tipo == 2) {
		this->camera.target(x, y);
	}
}

void Scene::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Click:  " << button << endl;
}

void Scene::Init() {
	ModelLoader* loader = new ModelLoader();

	switch (GetTipo()) {
	//ZONA PRUEBAS
	case 0:
	{
		this->camera.SetCoordinates(Vector3D(5, 20, 30));
		this->camera.SetOrientation(Vector3D(45, 0, 0));

		Model* cajaMedicina = new Model();
		Model* brazosPistola = new Model();
		Model* cangrejoMalo = new Model();
		Model* escenarioT = new Model();

		loader->LoadModel("..\\Assets\\Medicina.obj");
		*cajaMedicina = loader->GetModel();
		loader->Clear();

		loader->LoadModel("..\\Assets\\BrazosConPistola.obj");
		*brazosPistola = loader->GetModel();
		loader->Clear();

		loader->LoadModel("..\\Assets\\CangrejoMalo.obj");
		*cangrejoMalo = loader->GetModel();
		loader->Clear();

		loader->LoadModel("..\\Assets\\EscenarioT.obj");
		*escenarioT = loader->GetModel();
		loader->Clear();

		cajaMedicina->PaintColor(Color(1.0, 1.0, 1.0));
		brazosPistola->SetSpeedX(0.001);
		cangrejoMalo->SetSpeedY(-0.001);

		Teapot* teapot = new Teapot();
		Teapot* teapot2 = new Teapot();
		Cube* cube = new Cube();
		Cube* cube2 = new Cube();
		Sphere* sphere = new Sphere();
		Sphere* sphere2 = new Sphere();

		Prisma* prisma = new Prisma();
		Toroide* toroide = new Toroide();
		Cilindro* cilindro = new Cilindro();

		this->gameObjects.push_back(teapot);
		this->gameObjects.push_back(teapot2);
		this->gameObjects.push_back(cube);
		this->gameObjects.push_back(cube2);
		this->gameObjects.push_back(sphere);
		this->gameObjects.push_back(sphere2);

		this->gameObjects.push_back(prisma);
		this->gameObjects.push_back(toroide);
		this->gameObjects.push_back(cilindro);

		this->gameObjects.push_back(cajaMedicina);
		this->gameObjects.push_back(brazosPistola);
		this->gameObjects.push_back(cangrejoMalo);
		this->gameObjects.push_back(escenarioT);

		for (int i = 0; i < gameObjects.size(); i++) {
			gameObjects[i]->SetCoordinateX(3);
			gameObjects[i]->SetCoordinateY(3);
			gameObjects[i]->SetCoordinateZ(1);
		}

		escenarioT->SetCoordinateY(-10);

		escenarioT->SetSpeedX(0);
		escenarioT->SetSpeedY(0);
		escenarioT->SetSpeedZ(0);

		escenarioT->SetRotSpeedX(0);
		escenarioT->SetRotSpeedY(0);
		escenarioT->SetRotSpeedZ(0);

		escenarioT->SetRotX(0);
		escenarioT->SetRotY(0);
		escenarioT->SetRotZ(0);

		break;
	}

	//MENU PRINCIPAL
	case 1: {
		Teapot* teapot = new Teapot();
		this->gameObjects.push_back(teapot);

		this->camera.SetCoordinates(Vector3D(0,0,0));
		this->camera.SetOrientation(Vector3D(0,0,0));

		break;
	}

	//ESCENA DE JUEGO
	case 2: {
		Model* escenarioT = new Model();

		loader->LoadModel("..\\Assets\\EscenarioT.obj");
		*escenarioT = loader->GetModel();
		loader->Clear();

		escenarioT->SetCoordinateX(0);
		escenarioT->SetCoordinateY(-1);
		escenarioT->SetCoordinateZ(0);

		escenarioT->SetSpeedX(0);
		escenarioT->SetSpeedY(0);
		escenarioT->SetSpeedZ(0);

		escenarioT->SetRotSpeedX(0);
		escenarioT->SetRotSpeedY(0);
		escenarioT->SetRotSpeedZ(0);

		escenarioT->SetRotX(0);
		escenarioT->SetRotY(0);
		escenarioT->SetRotZ(0);

		this->gameObjects.push_back(escenarioT);

		break;
	}

	////ESCENA RESULTADOS
	//case 3:
	//	break;
	}
	


}

void Scene::Render() {
	camera.Render();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}

void Scene::Update(const float& time) {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update(time);
		checkBoundary(gameObjects[i]);
	}
}

void Scene::checkBoundary(Solid* object) {
	//EJE X
	if (object->GetCoordinateX() >= GetBoundaryX() || object->GetCoordinateX() <= - GetBoundaryX()) {
		object->SetSpeedX(-object->GetSpeedX());
	}
	//EJE Y
	if (object->GetCoordinateY() >= GetBoundaryY() || object->GetCoordinateY() <= - GetBoundaryY()) {
		object->SetSpeedY(-object->GetSpeedY());
	}
	//EJE Z
	if (object->GetCoordinateZ() >= GetBoundaryZ() || object->GetCoordinateZ() <= - GetBoundaryZ()) {
		object->SetSpeedZ(-object->GetSpeedZ());
	}
}

void Scene::Clear() {
	for (Solid* s : gameObjects) {
		delete s;
	}
	gameObjects.clear();
	cout << gameObjects.size();
}