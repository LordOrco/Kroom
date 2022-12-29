#pragma once
#include "Model.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class ModelLoader
{
private:
	float scale;

	float minX;
	float minY;
	float minZ;
	float maxX;
	float maxY;
	float maxZ;

	Model modelo;
	vector<Vector3D> vertexes;
	vector<Vector3D> normals;

	inline float getWidth(){ return (maxX - minX); }
	inline float getHeight(){ return (maxY - minY); }
	inline float getLength(){ return (maxZ - minZ); }
	void calcBoundaries(Vector3D vectorPoint);
	Triangle center(Triangle triangle);
	Vector3D parseObjLineToVector3D(const string& line);
	Triangle parseObjToTriangle(const string& line);

public:

	ModelLoader():
		scale(1),

		minX(0),
		minY(0),
		minZ(0),
		maxX(0),
		maxY(0),
		maxZ(0)
	
	{}


	inline Model GetModel() { return this->modelo; }
	inline float GetScale() { return this->scale; }
	inline void SetScale(float sizeToSet) { this->scale = sizeToSet; }

	void LoadModel(const string& filePath);
	void Clear();
};

