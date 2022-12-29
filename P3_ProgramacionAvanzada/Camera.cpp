#include "Camera.h"

void Camera::Render() {
	glTranslatef(-1 * GetCoordinateX(), -1 * GetCoordinateY(), -1 * GetCoordinateZ());
	glRotatef(GetRotX(), 1.0, 0.0, 0.0);
	glRotatef(GetRotY(), 0.0, 1.0, 0.0);
	glRotatef(GetRotZ(), 0.0, 0.0, 1.0);

}