#include "Camera.h"

void Camera::Render() {

    glRotatef(this->GetRotX(), 1.0, 0.0, 0.0);
    glRotatef(this->GetRotY(), 0.0, 1.0, 0.0);
    glTranslatef(-this->GetCoordinateX(), -this->GetCoordinateY(), -this->GetCoordinateZ());

}

void Camera::move(unsigned char key) {
    switch (key) {
    case 'w':
        this->SetCoordinateX(this->GetCoordinateX() + float(sin(this->GetRotY() * 3.141592654f / 180)) * 0.15);
        this->SetCoordinateZ(this->GetCoordinateZ() - float(cos(this->GetRotY() * 3.141592654f / 180)) * 0.15);
        cout <<"Y: " << this->GetRotY();                                                                  
        break;                                                                                            
    case 'a':                                                                                             
        this->SetCoordinateX(this->GetCoordinateX() - float(cos(this->GetRotY() * 3.141592654f / 180)) * 0.15);
        this->SetCoordinateZ(this->GetCoordinateZ() - float(sin(this->GetRotY() * 3.141592654f / 180)) * 0.15);
        break;                                                                                            
    case 's':                                                                                             
        this->SetCoordinateX(this->GetCoordinateX() - float(sin(this->GetRotY() * 3.141592654f / 180)) * 0.15);
        this->SetCoordinateZ(this->GetCoordinateZ() + float(cos(this->GetRotY() * 3.141592654f / 180)) * 0.15);
        break;                                                                                             
    case 'd':                                                                                              
        this->SetCoordinateX(this->GetCoordinateX() + float(cos(this->GetRotY() * 3.141592654f / 180)) * 0.15);
        this->SetCoordinateZ(this->GetCoordinateZ() + float(sin(this->GetRotY() * 3.141592654f / 180)) * 0.15);
        break;
    }
}

void Camera::target(int x, int y) {
    int diffx = x - lastx;
    int diffy = y - lasty;
    lastx = x; 
    lasty = y; 
    if (this->GetRotX() >= 360) {
        this->SetRotX(0);
    }
    else if (this->GetRotX() < 0) {
        this->SetRotX(360);
    }

    if (this->GetRotY() >= 360) {
        this->SetRotY(0);
    }
    else if (this->GetRotY() < 0) {
        this->SetRotY(360);
    }
    this->SetRotX(this->GetRotX() + (float)diffy);
    this->SetRotY(this->GetRotY() + (float)diffx);
}