#pragma once
#include "Triangle.h"
#include <vector>

class Model : public Solid
{
private:
	vector <Triangle> triangulos;

public:

	Model(): Solid(Vector3D(), Vector3D(), Color(), Vector3D(), Vector3D()) {};

	Model(Vector3D pos) : Solid(pos, Vector3D(), Color(), Vector3D(), Vector3D()) {};

	void AddTriangle(Triangle triangleToAdd);
	inline vector<Triangle> GetTriangles() { return this->triangulos; };
	inline void SetTriangles(vector<Triangle> trianglesToSet) {this->triangulos = trianglesToSet; };


	void PaintColor(Color colorToSet);

	void Clear();

	void Render();
};

