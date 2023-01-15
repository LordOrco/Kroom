#pragma once
#include "Solid.h"
#include "Sphere.h"

class Bala: public Sphere
{
private:

	int da�o;
	bool activa;
	int tipo;

public:

	Bala(Vector3D<float> pos, Vector3D<float> speed, int pTipo):
		Sphere(pos, speed),
		tipo(pTipo),
		da�o(pTipo),
		activa(true)
	{
		if (tipo == 1) {
			this->SetColor(Color(0, 0, 1));
		}
		else {
			this->SetColor(Color(1, 0.3, 0));
		}
	}

	inline int GetDa�oBala() const { return this->da�o; }
	inline bool GetActiva() const { return this->activa; }

	inline void SetDa�oBala(const int& da�oToSet) { this->da�o = da�oToSet; }
	inline void SetActiva(const bool& activaToSet) { this->activa = activaToSet; }

};

