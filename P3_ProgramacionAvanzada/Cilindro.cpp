#include "Cilindro.h"

void Cilindro::Render() {
	GLUquadricObj* quadricTemp = gluNewQuadric();
	glPushMatrix();
	glTranslatef(GetCoordinateX(), GetCoordinateY(), GetCoordinateZ());
	glColor3f(GetRedComponent(), GetGreenComponent(), GetBlueComponent());
	glRotatef(GetRotX(), 1.0, 0.0, 0.0);
	glRotatef(GetRotY(), 0.0, 1.0, 0.0);
	glRotatef(GetRotZ(), 0.0, 0.0, 1.0);
	gluCylinder(quadricTemp, GetLowerRadius(), GetUpperRadius(), GetHeight(), GetSlices(), GetStacks());
	glPopMatrix();
	gluDeleteQuadric(quadricTemp);
}
