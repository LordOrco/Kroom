#include "Scene.h"

void Scene::Render() {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
	for (int i = 0; i < powerUps.size(); i++) {
		powerUps[i]->Render();
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Render();
	}
	for (int i = 0; i < text.size(); i++) {
		text[i]->Render();
	}
}

void Scene::Update(const float& time) {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update(time);
	}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Update(time);
		if (!bullets[i]->GetActiva()) {
			this->DeleteBullet(i);
		}
	}
	for (int i = 0; i < powerUps.size(); i++) {
		powerUps[i]->Update(time);
		if (!powerUps[i]->GetActiva()) {
			this->DeletePowerUp(i);
		}
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Update(time);
		if (enemies[i]->GetHP() <= 0) {
			this->DeleteEnemy(i);
		}
	}
}

void Scene::Clear() {
	for (Bala* s : bullets) {
		delete s;
	}
	for (Enemigo* s : enemies) {
		delete s;
	}
	for (BalaPowerUp* s : powerUps) {
		delete s;
	}
	for (Text* s : text) {
		delete s;
	}

	bullets.clear();
	enemies.clear();
	powerUps.clear();
	text.clear();

	cout << gameObjects.size();
}