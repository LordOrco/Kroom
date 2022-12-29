#include "Sphere.h"

void Sphere::Render() {
	glPushMatrix();
	glTranslatef(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());
	glRotatef(this->GetRotX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotZ(), 0.0, 0.0, 1.0);
	glutSolidSphere(this->GetRadius(), this->GetSlices(), this->GetSlacks());
	glPopMatrix();
}