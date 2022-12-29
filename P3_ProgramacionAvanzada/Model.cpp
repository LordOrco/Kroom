#include "Model.h"

void Model::Render() {
	glPushMatrix();
	glTranslatef(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());
	glRotatef(this->GetRotX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotZ(), 0.0, 0.0, 1.0);

	for (Triangle& t : this->triangulos) {
		t.Render();
	}

	glPopMatrix();
}

void Model::AddTriangle(Triangle triangleToAdd) {
	triangulos.push_back(triangleToAdd);
}

void Model::PaintColor(Color colorToSet) {
	for (int i = 0; i < triangulos.size(); i++) {
		triangulos[i].SetVer1Color(colorToSet);
		triangulos[i].SetVer2Color(colorToSet);
		triangulos[i].SetVer3Color(colorToSet);
	}
}

void Model::Clear() {
	triangulos.clear();
}

