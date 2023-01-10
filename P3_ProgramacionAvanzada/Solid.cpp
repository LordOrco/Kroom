#include "Solid.h"

void Solid::Update(const float& time) {
	this->SetCoordinates(this->GetCoordinates() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetRotationSpeed() * time);
}