#include "ObjetoRenderizable.h"

void ObjetoRenderizable::Render()
{
	glPushMatrix();
	glTranslatef(GetCoordinateX(), GetCoordinateY(), GetCoordinateZ());
	glColor3f(GetRedComponent(), GetGreenComponent(), GetBlueComponent());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);

	this->renderizable.Render();

	glPopMatrix();
}