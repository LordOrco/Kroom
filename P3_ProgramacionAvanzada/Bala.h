#pragma once
#include "ObjetoRenderizable.h"

class Bala
{
private:

	int daño;

public:

	Bala():
		daño(0)
	{}

	inline int GetDañoBala() const { return this->daño; }

	inline void SetDañoBala(const int& dañoToSet) { this->daño = dañoToSet; }

};

