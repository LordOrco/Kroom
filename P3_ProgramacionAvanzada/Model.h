#pragma once
#include "Triangle.h"
#include <vector>

class Model : public Solid
{
private:
	vector <Triangle> triangulos;

public:

	Model(): Solid(Vector3D<float>(), Vector3D<float>(), Color(), Vector3D<float>(), Vector3D<float>()) {};

	Model(Vector3D<float> pos) : Solid(pos, Vector3D<float>(), Color(), Vector3D<float>(), Vector3D<float>()) {};

	void AddTriangle(Triangle triangleToAdd);
	inline vector<Triangle> GetTriangles() { return this->triangulos; };
	inline void SetTriangles(vector<Triangle> trianglesToSet) {this->triangulos = trianglesToSet; };


	void PaintColor(Color colorToSet);

	void Clear();

	void Render();
};

