#pragma once
#include "Solid.h"
#include "Sphere.h"

class Bala: public Sphere
{
private:

	int daño;
	bool activa;
	int tipo;

public:

	Bala(Vector3D<float> pos, Vector3D<float> speed, int pTipo):
		Sphere(pos, speed),
		tipo(pTipo),
		daño(pTipo),
		activa(true)
	{
		if (tipo == 1) {
			this->SetColor(Color(0, 0, 1));
		}
		else {
			this->SetColor(Color(1, 0.3, 0));
		}
	}

	inline int GetDañoBala() const { return this->daño; }
	inline bool GetActiva() const { return this->activa; }

	inline void SetDañoBala(const int& dañoToSet) { this->daño = dañoToSet; }
	inline void SetActiva(const bool& activaToSet) { this->activa = activaToSet; }

};

