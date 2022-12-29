#include "Prisma.h"

void Prisma::Render() {
	glPushMatrix();
	glTranslatef(GetCoordinateX(), GetCoordinateY(), GetCoordinateZ());
	glColor3f(GetRedComponent(), GetGreenComponent(), GetBlueComponent());
	glRotatef(GetRotX(), 1.0, 0.0, 0.0);
	glRotatef(GetRotY(), 0.0, 1.0, 0.0);
	glRotatef(GetRotZ(), 0.0, 0.0, 1.0);
	glScalef(GetLength(), GetHeight(), GetDepth());
	glutSolidCube(1);
	glPopMatrix();
}
