#pragma once
#include <vector>
#include "Camera.h"
#include "Sphere.h"
#include "ModelLoader.h"
#include "BalaPowerUp.h"
#include "Bala.h"
#include "Personaje.h"
#include "Enemigo.h"

class Scene
{
private:
	vector <Solid*> gameObjects;
	vector <Bala*> bullets;
	vector <BalaPowerUp*> powerUps;
	vector <Enemigo*> enemies;

public:
	Scene(){}

	inline vector <Solid*> GetGameObjects() { return this->gameObjects; }
	inline vector <Bala*> GetBullets() { return this->bullets; }
	inline vector <BalaPowerUp*> GetPowerUps() { return this->powerUps; }
	inline vector <Enemigo*> GetEnemies() { return this->enemies; }

	inline Solid* GetGameObject(int index) { return this->gameObjects[index]; }

	inline void SetGameObject(int index, Solid* solidToSet) { this->gameObjects[index] = solidToSet; }
	inline void SetBullet(int index, Bala* solidToSet) { this->bullets[index] = solidToSet; }
	inline void SetPowerUps(int index, BalaPowerUp* solidToSet) { this->powerUps[index] = solidToSet; }
	inline void SetEnemy(int index, Enemigo* solidToSet) { this->enemies[index] = solidToSet; }

	inline void AddGameObject(Solid* solidToAdd) { this->gameObjects.push_back(solidToAdd); }
	inline void AddBullet(Bala* solidToAdd) { this->bullets.push_back(solidToAdd); }
	inline void AddPowerUp(BalaPowerUp* solidToAdd) { this->powerUps.push_back(solidToAdd); }
	inline void AddEnemy(Enemigo* solidToAdd) { this->enemies.push_back(solidToAdd); }

	inline void DeleteGameObject(int index) { delete this->gameObjects[index]; this->gameObjects.erase(gameObjects.begin() + index);}
	inline void DeleteBullet(int index) { delete this->bullets[index];  this->bullets.erase(bullets.begin() + index); }
	inline void DeletePowerUp(int index) { delete this->powerUps[index];  this->powerUps.erase(powerUps.begin() + index); }
	inline void DeleteEnemy(int index) { delete this->enemies[index]; this->enemies.erase(enemies.begin() + index); }

	void Render();
	void Update(const float& time);
	void Clear();
};

