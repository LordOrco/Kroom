#include "Solid.h"

void Solid::Update() {
	SetCoordinates(GetCoordinates() + GetSpeed());
	SetOrientation(GetOrientation() + GetRotationSpeed());
}