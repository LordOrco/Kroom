#include "Game.h"

using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	//cout << "Tecla pulsada " << key << endl;
	switch (escenaActual) {
	case 1:
		switch (key) {
		case '1':
			SetEscenaActual(2);
			newGame();
			break;
		case '2':
			SetEscenaActual(3);
			break;
		}
		break;

	case 2:
		switch (key) {
		case 'w':
			wPressed = true;
			break;
		case 'a':
			aPressed = true;
			break;
		case 's':
			sPressed = true;
			break;
		case 'd':
			dPressed = true;
			break;
		case 'x':
			SetEscenaActual(1);
			newSave();
			break;
		}
		break;
	case 3:
		if (key == '1') {
			SetEscenaActual(1);
		}
	}
}

void Game::ProcessKeyUp(unsigned char key, int px, int py) {
	//cout << "Tecla pulsada " << key << endl;
	if(escenaActual == 2){
		switch (key) {
		case 'w':
			wPressed = false;
			break;
		case 'a':
			aPressed = false;
			break;
		case 's':
			sPressed = false;
			break;
		case 'd':
			dPressed = false;
			break;
		default:
			break;
		}
	}
	else {
		this->camera.placeInMenu();
		wPressed = false;
		aPressed = false;
		sPressed = false;
		dPressed = false;
	}
}

void Game::ProcessMouseMovement(int x, int y) {
	//cout << "Movimiento del raton " <<	x << ", " << y << endl;
	if (GetEscenaActual() == 2) {
		this->camera.target(x, y);
		personaje.Update(TIME_INCREMENT);
	}
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	//cout << "Click:  " << button << endl;
	if (GetEscenaActual() == 2 && button == 0 && state == 0) {
		shoot();
	}
}

void Game::Init() {
	//Colocacion de camara
	this->camera.placeInMenu();

	//Lectura de archivo de guardado
	saveManage();

	//Creacion de modelos
	Model* titulo = new Model();
	Model* puntuacion = new Model();
	Model* mPersonaje = new Model();
	Model* balaPowerUp = new Model();
	Model* cangrejoMalo = new Model();
	Model* escenarioT = new Model();
	Model* fondo = new Model();
	Sphere* bala = new Sphere();

	//Cargado de modelos
	ModelLoader* loader = new ModelLoader();

	loader->LoadModel("..\\Assets\\Medicina.obj");
	*balaPowerUp = loader->GetModel();
	loader->Clear();

	loader->SetScale(0.25);
	loader->LoadModel("..\\Assets\\BrazosConPistola.obj");
	*mPersonaje = loader->GetModel();
	loader->Clear();

	loader->SetScale(1);
	loader->LoadModel("..\\Assets\\CangrejoMalo.obj");
	*cangrejoMalo = loader->GetModel();
	loader->Clear();

	loader->SetScale(7);
	loader->LoadModel("..\\Assets\\EscenarioT.obj");
	*escenarioT = loader->GetModel();
	loader->Clear();

	loader->SetScale(1);
	loader->LoadModel("..\\Assets\\Titulo.obj");
	*titulo = loader->GetModel();
	loader->Clear();

	loader->SetScale(1);
	loader->LoadModel("..\\Assets\\Puntuacion.obj");
	*puntuacion = loader->GetModel();
	loader->Clear();

	loader->SetScale(6);
	loader->LoadModel("..\\Assets\\EscenarioT.obj");
	*fondo = loader->GetModel();
	loader->Clear();

	//Colores de modelos
	titulo->PaintColor(Color(1, 1, 1));
	fondo->PaintColor(Color(0.2, 0.2, 0.2));
	puntuacion->PaintColor(Color(0, 0, 0));
	balaPowerUp->PaintColor(Color(0.01, 0.5, 0.01));
	mPersonaje->PaintColor(Color(0.3, 0.3, 0.3));
	cangrejoMalo->PaintColor(Color(1, 0.1, 0.1));
	escenarioT->PaintColor(Color(0.5, 0.5, 1));

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

	fondo->SetRotX(90);
	fondo->SetCoordinateX(1);
	fondo->SetCoordinateZ(-26);


	//Meter los modelos en el vector de objetos para renderizar
	renderizables.push_back(balaPowerUp);
	renderizables.push_back(mPersonaje);
	renderizables.push_back(cangrejoMalo);
	renderizables.push_back(escenarioT);
	renderizables.push_back(titulo);
	renderizables.push_back(puntuacion);
	renderizables.push_back(fondo);

	//Añadir modelos a la escena
	personaje.SetTriangles(mPersonaje->GetTriangles());
	escenas[2].AddGameObject(&personaje);
	escenas[2].AddGameObject(renderizables[3]);


	titulo->SetCoordinateZ(-20);
	titulo->SetCoordinateY(1);
	titulo->SetCoordinateX(0);
	escenas[1].AddGameObject(renderizables[4]);

	puntuacion->SetCoordinateZ(-15);
	puntuacion->SetCoordinateY(-2);
	puntuacion->SetCoordinateX(0);
	escenas[3].AddGameObject(renderizables[5]);

	escenas[3].AddGameObject(renderizables[6]);

	glutWarpPointer(400, 300);
	spawnEnemy();
	spawnBalaPowerUp();
}

void Game::Render() {
	this->camera.Render();
	this->escenas[escenaActual].Render();
	//cout << "RENDER" << endl;
}

void Game::Update() {
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMiliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD) {
		if (escenaActual == 2) {
			step();
			movimientoJugador();
			checkBoundary();
			collisions();
		}
		this->escenas[escenaActual].Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMiliseconds.count();
	}
}

void Game::shoot() {
	escenas[2].AddBullet(personaje.shoot());
}

void Game::step() {
	if (rand() % 50 == 0) {
		spawnEnemy();
	}
	if (rand() % 500 == 0) {
		spawnBalaPowerUp();
	}
}

void Game::spawnEnemy() {
	Enemigo* enemigo = new Enemigo(Vector3D(rand() % (61) - 30, 0, rand() % (61) - 30), &personaje); //rand()%(max-min + 1) + min
	enemigo->SetTriangles(renderizables[2]->GetTriangles());
	escenas[2].AddEnemy(enemigo);
}

void Game::spawnBalaPowerUp() {
	BalaPowerUp* caja = new BalaPowerUp(Vector3D(rand() % (51) - 25, -0.5, rand() % (51) - 25)); //rand()%(max-min + 1) + min
	caja->SetTriangles(renderizables[0]->GetTriangles());
	escenas[2].AddPowerUp(caja);
}

void Game::movimientoJugador() {
	if (wPressed) {
		this->camera.move('w');
	}
	if (aPressed) {
		this->camera.move('a');
	}
	if (sPressed) {
		this->camera.move('s');
	}
	if (dPressed) {
		this->camera.move('d');
	}
}

void Game::collisions() {

	for (int i = 0; i < escenas[escenaActual].GetPowerUps().size(); i++) {
		if ((escenas[escenaActual].GetPowerUps()[i]->GetCoordinates() - this->camera.GetCoordinates()).modulo() < 2) {
			//cout << "Caja Recogida" << endl;
			personaje.SetBalasMejoradas(personaje.GetBalasMejoradas() + escenas[escenaActual].GetPowerUps()[i]->GetBalasMejoradas());
			escenas[escenaActual].GetPowerUps()[i]->SetActiva(false);
		}
	}

	for (int i = 0; i < escenas[escenaActual].GetEnemies().size(); i++) {
		if ((escenas[escenaActual].GetEnemies()[i]->GetCoordinates() - this->camera.GetCoordinates()).modulo() < 2) {
			//cout << "MUERTE" << endl;
			escenaActual = 3;
			newSave();
			this->camera.placeInMenu();
		}
		for (int j = 0; j < escenas[escenaActual].GetBullets().size(); j++) {
			if ((escenas[escenaActual].GetEnemies()[i]->GetCoordinates() - escenas[escenaActual].GetBullets()[j]->GetCoordinates()).modulo() < 1.5) {
				//cout << "HIT" << endl;
				escenas[escenaActual].GetEnemies()[i]->PaintColor(Color(escenas[escenaActual].GetEnemies()[i]->GetTriangles()[0].GetVer1Color().GetRedComponent() - 0.2, 0.1, 0.1));
				escenas[escenaActual].GetBullets()[j]->SetActiva(false);
				escenas[escenaActual].GetEnemies()[i]->SetHP(escenas[escenaActual].GetEnemies()[i]->GetHP() - escenas[escenaActual].GetBullets()[j]->GetDañoBala());
				personaje.SetScore(personaje.GetScore() + 5);
			}
		}
	}
}

void Game::checkBoundary() {
	for (int i = 0; i < escenas[escenaActual].GetBullets().size(); i++) {
		if (escenas[escenaActual].GetBullets()[i]->GetCoordinates().modulo() > GetBoundaryRadius()) {
			escenas[escenaActual].DeleteBullet(i);
		}
	}
	if (this->camera.GetCoordinates().modulo() > GetBoundaryRadius()) {
		this->camera.SetCoordinates(Vector3D(this->camera.GetLastX(), this->camera.GetCoordinateY(), this->camera.GetLastZ()));
	}
}

void Game::newGame() {
	this->camera.placeInMenu();
	escenas[2].Clear();
	personaje.reset();
}

void Game::saveManage() {
	if (guardado.existFile()) {
		guardado.loadFile();
	}
	else {
		guardado.saveFile();
	}

	updateScores();
}


void Game::newSave() {
	guardado.SetLastGame(personaje.GetScore());
	guardado.SetTotalGames(guardado.GetTotalGames() + 1);

	if (personaje.GetScore() > guardado.GetTop1()) {
		guardado.SetTop5(guardado.GetTop4());
		guardado.SetTop4(guardado.GetTop3());
		guardado.SetTop3(guardado.GetTop2());
		guardado.SetTop2(guardado.GetTop1());
		guardado.SetTop1(personaje.GetScore());
	}
	else if (personaje.GetScore() > guardado.GetTop2()) {
		guardado.SetTop5(guardado.GetTop4());
		guardado.SetTop4(guardado.GetTop3());
		guardado.SetTop3(guardado.GetTop2());
		guardado.SetTop2(personaje.GetScore());
	}
	else if (personaje.GetScore() > guardado.GetTop3()) {
		guardado.SetTop5(guardado.GetTop4());
		guardado.SetTop4(guardado.GetTop3());
		guardado.SetTop3(personaje.GetScore());
	}
	else if (personaje.GetScore() > guardado.GetTop4()) {
		guardado.SetTop5(guardado.GetTop4());
		guardado.SetTop4(personaje.GetScore());
	}
	else if (personaje.GetScore() > guardado.GetTop5()) {
		guardado.SetTop5(personaje.GetScore());
	}

	guardado.saveFile();
	updateScores();
}

void Game::updateScores() {

	Text* top1 = new Text(to_string(guardado.GetTop1()), Vector3D(-1.2, 0.25, -2));
	Text* top2 = new Text(to_string(guardado.GetTop2()), Vector3D(-1.2, 0.08, -2));
	Text* top3 = new Text(to_string(guardado.GetTop3()), Vector3D(-1.2, -0.11, -2));
	Text* top4 = new Text(to_string(guardado.GetTop4()), Vector3D(-1.2, -0.29, -2));
	Text* top5 = new Text(to_string(guardado.GetTop5()), Vector3D(-1.2, -0.46, -2));
	Text* lastGame = new Text(to_string(guardado.GetLastGame()), Vector3D(0.7, 0.2, -2));
	Text* totalGames = new Text(to_string(guardado.GetTotalGames()), Vector3D(0.7, -0.25, -2));

	escenas[3].Clear();

	escenas[3].AddText(top1);
	escenas[3].AddText(top2);
	escenas[3].AddText(top3);
	escenas[3].AddText(top4);
	escenas[3].AddText(top5);
	escenas[3].AddText(lastGame);
	escenas[3].AddText(totalGames);
}