#include "Toroide.h"

void Toroide::Render() {
	glPushMatrix();
	glTranslatef(GetCoordinateX(), GetCoordinateY(), GetCoordinateZ());
	glColor3f(GetRedComponent(), GetGreenComponent(), GetBlueComponent());
	glRotatef(GetRotX(), 1.0, 0.0, 0.0);
	glRotatef(GetRotY(), 0.0, 1.0, 0.0);
	glRotatef(GetRotZ(), 0.0, 0.0, 1.0);
	glutSolidTorus(GetInternalRadius(), GetExternalRadius(), GetFaces(), GetRings());
	glPopMatrix();
}
