#include "Personaje.h"

void Personaje::Update(const float& time) {

	this->SetRotX(-this->camara->GetRotX());
	this->SetRotY(-this->camara->GetRotY());
	
	this->SetCoordinateX(this->camara->GetCoordinateX());
	this->SetCoordinateY(0.6);
	this->SetCoordinateZ(this->camara->GetCoordinateZ());

	cout << "personaje Update" << endl;
}

Bala* Personaje::shoot() {
	Vector3D<float> balaPos(Vector3D<float>(this->GetCoordinateX() - 0.025f - float(sin(this->GetRotY() * 3.141592654f / 180)),
		-0.1 + float(sin(this->GetRotX() * 3.141592654f / 180)),
		this->GetCoordinateZ() - float(cos(this->GetRotY() * 3.141592654f / 180))
	));

	Vector3D<float> balaSpeed(-float(sin(this->GetRotY() * 3.141592654f / 180)) * 25,
		float(sin(this->GetRotX() * 3.141592654f / 180)) * 25,
		-float(cos(this->GetRotY() * 3.141592654f / 180)) * 25);

	int balaTipo = 1;
	if (this->GetBalasMejoradas() > 0) {
		balaTipo = 2;
		this->SetBalasMejoradas(this->GetBalasMejoradas() - 1);
	}

	Bala* bala = new Bala(balaPos, balaSpeed, balaTipo);

	return bala;
}
