#include "Scene.h"

void Scene::Render() {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Render();
	}
}

void Scene::Update(const float& time) {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update(time);
	}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Update(time);
		
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Update(time);
		if (enemies[i]->GetHP() <= 1) {
			this->DeleteEnemy(i);
		}
	}
}

void Scene::Clear() {
	for (Sphere* s : bullets) {
		delete s;
	}
	for (Enemigo* s : enemies) {
		delete s;
	}

	bullets.clear();
	enemies.clear();

	cout << gameObjects.size();
}