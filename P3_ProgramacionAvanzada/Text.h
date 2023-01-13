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
		Solid(Vector3D(), Vector3D(), Color(), Vector3D(), Vector3D()),
		text("The quick god jumps over the lazy brown fox.")
	{}

	Text(string pString, Vector3D pPosition) :
		Solid(pPosition, Vector3D(), Color(), Vector3D(), Vector3D()),
		text(pString)
	{}

	inline string GetString() { return this->text; }

	inline void SetString(string stringToSet) { this->text = stringToSet; }
	
	void Render();
};

