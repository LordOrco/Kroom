#include "Scene.h"

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada " << key << endl;
}

void Scene::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del raton " << x << ", " << y << endl;
}

void Scene::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Click:  " << button << endl;
}

void Scene::Init() {
	
	Camera* camera = new Camera(Vector3D(4, 3, 12));

	ModelLoader* loader = new ModelLoader();
	Model* cajaMedicina = new Model();
	Model* brazosPistola = new Model();
	Model* cangrejoMalo = new Model();

	loader->LoadModel("..\\Assets\\Medicina.obj");
	*cajaMedicina = loader->GetModel();
	loader->Clear();

	loader->LoadModel("..\\Assets\\BrazosConPistola.obj");
	*brazosPistola = loader->GetModel();
	loader->Clear();

	loader->LoadModel("..\\Assets\\CangrejoMalo.obj");
	*cangrejoMalo = loader->GetModel();
	loader->Clear();

	cajaMedicina->PaintColor(Color(1.0, 1.0, 1.0));
	brazosPistola->SetSpeedX(0.001);
	cangrejoMalo->SetSpeedY(0.001);

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


	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->SetCoordinateX(3);
		gameObjects[i]->SetCoordinateY(3);
		gameObjects[i]->SetCoordinateZ(1);
	}
}

void Scene::Render() {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}

void Scene::Update() {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update();
		checkBoundary(gameObjects[i]);
	}
}

void Scene::checkBoundary(Solid* object) {
	//EJE X
	if (object->GetCoordinateX() >= GetBoundaryX() || object->GetCoordinateX() <= 0) {
		object->SetSpeedX(-object->GetSpeedX());
	}
	//EJE Y
	if (object->GetCoordinateY() >= GetBoundaryY() || object->GetCoordinateY() <= 0) {
		object->SetSpeedY(-object->GetSpeedY());
	}
	//EJE Z
	if (object->GetCoordinateZ() >= GetBoundaryZ() || object->GetCoordinateZ() <= 0) {
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