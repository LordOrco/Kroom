#pragma once
#include "ObjetoRenderizable.h"

class Bala
{
private:

	int da�o;

public:

	Bala():
		da�o(0)
	{}

	inline int GetDa�oBala() const { return this->da�o; }

	inline void SetDa�oBala(const int& da�oToSet) { this->da�o = da�oToSet; }

};

