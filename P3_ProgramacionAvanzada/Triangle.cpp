#include "Triangle.h"

void Triangle::Render() {
	glBegin(GL_TRIANGLES);

	//vétice 1
	glColor3f(color1.GetRedComponent(), color1.GetGreenComponent(), color1.GetBlueComponent());
	glNormal3f(norm1.GetX(), norm1.GetY(), norm1.GetZ());
	glVertex3f(ver1.GetX(), ver1.GetY(), ver1.GetZ());
	//cout << "Vertice 1: " << ver1.GetX() << ", " << ver1.GetY() << ", " << ver1.GetZ() << endl;

	//vértice 2
	glColor3f(color2.GetRedComponent(), color2.GetGreenComponent(), color2.GetBlueComponent());
	glNormal3f(norm2.GetX(), norm2.GetY(), norm2.GetZ());
	glVertex3f(ver2.GetX(), ver2.GetY(), ver2.GetZ());
	//cout << "Vertice 2: " << ver2.GetX() << ", " << ver2.GetY() << ", " << ver2.GetZ() << endl;

	//vértice 3
	glColor3f(color3.GetRedComponent(), color3.GetGreenComponent(), color3.GetBlueComponent());
	glNormal3f(norm3.GetX(), norm3.GetY(), norm3.GetZ());
	glVertex3f(ver3.GetX(), ver3.GetY(), ver3.GetZ());
	//cout << "Vertice 3: " << ver3.GetX() << ", " << ver3.GetY() << ", " << ver3.GetZ() << endl << endl;

	glEnd();

}