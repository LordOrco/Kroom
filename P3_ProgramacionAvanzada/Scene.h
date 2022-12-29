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

class Scene
{
private:
	vector <Solid*> gameObjects;
	Vector3D boundary;
	void checkBoundary(Solid* object);

public:
	Scene():
		boundary(8, 6, 4)
	{}

	inline vector <Solid*> GetGameObjects() { return this->gameObjects; }
	inline Solid* GetGameObject(int index) { return this->gameObjects[index]; }
	inline void SetGameObject(int index, Solid* solidToSet) { this->gameObjects[index] = solidToSet; }
	inline Vector3D GetBoundary() const { return this->boundary; }

	inline float GetBoundaryX() const { return this->boundary.GetX(); }
	inline float GetBoundaryY() const { return this->boundary.GetY(); }
	inline float GetBoundaryZ() const { return this->boundary.GetZ(); }

	inline void SetBoundary(const Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }
	inline void SetBoundaryX(const float& boundaryXToSet) { this->boundary.SetX(boundaryXToSet); }
	inline void SetBoundaryY(const float& boundaryYToSet) { this->boundary.SetY(boundaryYToSet); }
	inline void SetBoundaryZ(const float& boundaryZToSet) { this->boundary.SetZ(boundaryZToSet); }

	void Init();
	void Render();
	void Update();
	void Clear();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};

