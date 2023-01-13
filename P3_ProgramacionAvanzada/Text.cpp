#include "Text.h"

void Text::Render() {

	glPushMatrix();

	glTranslatef(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());

	glRotatef(this->GetRotX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotZ(), 0.0, 0.0, 1.0);

	glRasterPos3f(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	int len = text.size();
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
	}
	glPopMatrix();
}