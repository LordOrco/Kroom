#pragma once
#include <vector>
#include "Camera.h"
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Prisma.h"
#include "Toroide.h"
#include "Cilindro.h"
#include "ModelLoader.h"
#include "Medicina.h"
#include "Bala.h"
#include "Personaje.h"

class Scene
{
private:
	vector <Solid*> gameObjects;
	Vector3D boundary;
	int tipo;
	void checkBoundary(Solid* object);

public:
	Scene(int type) :
		tipo(type),
		boundary(20, 5, 20)
	{}

	inline vector <Solid*> GetGameObjects() { return this->gameObjects; }
	inline Solid* GetGameObject(int index) { return this->gameObjects[index]; }
	inline Vector3D GetBoundary() const { return this->boundary; }
	inline void SetGameObject(int index, Solid* solidToSet) { this->gameObjects[index] = solidToSet; }
	inline void AddGameObject(Solid* solidToAdd) { this->gameObjects.push_back(solidToAdd); }

	inline float GetBoundaryX() const { return this->boundary.GetX(); }
	inline float GetBoundaryY() const { return this->boundary.GetY(); }
	inline float GetBoundaryZ() const { return this->boundary.GetZ(); }
	inline int GetTipo() const { return this->tipo; }

	inline void SetBoundary(const Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }
	inline void SetBoundaryX(const float& boundaryXToSet) { this->boundary.SetX(boundaryXToSet); }
	inline void SetBoundaryY(const float& boundaryYToSet) { this->boundary.SetY(boundaryYToSet); }
	inline void SetBoundaryZ(const float& boundaryZToSet) { this->boundary.SetZ(boundaryZToSet); }

	void Init();
	void Render();
	void Update(const float& time);
	void Clear();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};

