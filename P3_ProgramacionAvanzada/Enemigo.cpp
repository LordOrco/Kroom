#include "Enemigo.h"

void Enemigo::Update(const float& time) {
	this->SetCoordinates(Vector3D(this->GetCoordinateX() - (this->GetCoordinateX() - this->GetToFollow()->GetCoordinateX())/100,
								  this->GetCoordinateY(),
								  this->GetCoordinateZ() - (this->GetCoordinateZ() - this->GetToFollow()->GetCoordinateZ())/100));
	this->SetOrientation(Vector3D(0,0,0));
}