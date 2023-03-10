#include "ModelLoader.h"

void ModelLoader::LoadModel(const string& filePath) {
	try {
		ifstream objFile(filePath);
		if (objFile.is_open()) {
			string line;
			int count = 0;
			while (getline(objFile, line)) {
				if (line[0] == 'v' && line[1] == 'n') {
					Vector3D<float> normal = this->parseObjLineToVector3D(line);
					this->normals.push_back(normal);
				}
				else if (line[0] == 'v') {
					Vector3D<float> vertex = this->parseObjLineToVector3D(line);
					this->calcBoundaries(vertex);
					this->vertexes.push_back(vertex);
				}
				else if (line[0] == 'f') {
					Triangle triangle = this->parseObjToTriangle(line);
					this->modelo.AddTriangle(this->center(triangle));
				}
			}
			objFile.close();
		}
		else {
			cout << "No se ha podido abrir el archivo: " << filePath << endl;
		}
	}
	catch (exception& ex) {
		cout << "Excepci?n al procesar el archivo: " << filePath << endl;
		cout << ex.what() << endl;
	}
}

Vector3D<float> ModelLoader::parseObjLineToVector3D(const string& line) {
	string typeOfPoint;
	float xCoordinate, yCoordinate, zCoordinate;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;
	Vector3D<float> vectorPoint(xCoordinate, yCoordinate, zCoordinate);
	return vectorPoint * this->GetScale();
}

Triangle ModelLoader::parseObjToTriangle(const string& line) {
	char c;
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;
	istringstream stringStream(line);
	stringStream >> c;
	stringStream >> idxVertex0 >> c >> c >> idxNormal0;
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;

	Vector3D<float> vertex0 = this->vertexes[idxVertex0 - 1];
	Vector3D<float> vertex1 = this->vertexes[idxVertex1 - 1];
	Vector3D<float> vertex2 = this->vertexes[idxVertex2 - 1];
	Vector3D<float> normal = this->normals[idxNormal0 - 1];

	Triangle parsedTriangle(vertex0, vertex1, vertex2, normal, normal, normal);

	return parsedTriangle;
}

void ModelLoader::calcBoundaries(Vector3D<float> vectorPoint) {
	this->maxX = fmax(this->maxX, vectorPoint.GetX());
	this->maxY = fmax(this->maxY, vectorPoint.GetY());
	this->maxZ = fmax(this->maxZ, vectorPoint.GetZ());

	this->minX = fmin(this->minX, vectorPoint.GetX());
	this->minY = fmin(this->minY, vectorPoint.GetY());
	this->minZ = fmin(this->minZ, vectorPoint.GetZ());
}

Triangle ModelLoader::center(Triangle triangle) {
	Vector3D<float> modelCenter(
		this->minX + this->getWidth() / 2.0,
		this->minY + this->getHeight() / 2.0,
		this->minZ + this->getLength() / 2.0);

	Triangle centeredTriangle(
		triangle.GetVer1Pos() - modelCenter,
		triangle.GetVer2Pos() - modelCenter,
		triangle.GetVer3Pos() - modelCenter,
		triangle.GetVer1Normal(),
		triangle.GetVer2Normal(),
		triangle.GetVer3Normal());

		return centeredTriangle;
}

void ModelLoader::Clear() {
	normals.clear();
	vertexes.clear();
	modelo.Clear();
}