#pragma once
#include "GL/glut.h"
#include "Vector3D.h"
#include "Color.h"
#include <string>
#include "Solid.h"

class Text: public Solid
{
private:
	string text;

public:
	

	Text() :
		Solid(Vector3D<float>(), Vector3D<float>(), Color(), Vector3D<float>(), Vector3D<float>()),
		text("The quick god jumps over the lazy brown fox.")
	{}

	Text(string pString, Vector3D<float> pPosition) :
		Solid(pPosition, Vector3D<float>(), Color(), Vector3D<float>(), Vector3D<float>()),
		text(pString)
	{}

	inline string GetString() { return this->text; }

	inline void SetString(string stringToSet) { this->text = stringToSet; }
	
	void Render();
};

