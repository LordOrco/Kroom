#pragma once
#include "Triangle.h"
#include <vector>

class Model : public Solid
{
private:
	vector <Triangle> triangulos;

public:

	Model(): Solid(Vector3D(0), Vector3D(0), Color(), Vector3D(0) / 100, Vector3D(0) / 10) {};

	void AddTriangle(Triangle triangleToAdd);
	void PaintColor(Color colorToSet);
	void Clear();

	void Render();
};

