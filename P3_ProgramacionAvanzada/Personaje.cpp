#include "Personaje.h"

void Personaje::Update(const float& time) {

	this->SetRotX(-this->camara->GetRotX());
	this->SetRotY(-this->camara->GetRotY());
	//this->SetRotZ(this->camara->GetRotZ());
	
	this->SetCoordinateX(this->camara->GetCoordinateX());
	this->SetCoordinateY(0.6);
	this->SetCoordinateZ(this->camara->GetCoordinateZ());

	cout << "personaje Update" << endl;
}

