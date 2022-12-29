#pragma once
#include <iostream>
class Color
{
private:
	float redComponent;
	float greenComponent;
	float blueComponent;

public:

	Color() :
		redComponent((float)rand() / (RAND_MAX)),
		greenComponent((float)rand() / (RAND_MAX)),
		blueComponent((float)rand() / (RAND_MAX)) {}

	Color(float component) :
		redComponent(component),
		greenComponent(component),
		blueComponent(component) {}

	Color(float redComponentToSet, float greenComponentToSet, float blueComponentToSet) :
		redComponent(redComponentToSet),
		greenComponent(greenComponentToSet),
		blueComponent(blueComponentToSet) {}

	inline float GetRedComponent() const { return this->redComponent; }
	inline float GetGreenComponent() const { return this->greenComponent; }
	inline float GetBlueComponent() const { return this->blueComponent; }

	void SetRedComponent(const float& redComponentToSet);
	void SetGreenComponent(const float& greenComponentToSet);
	void SetBlueComponent(const float& blueComponentToSet);

	float clamp(float floatToClamp);
};

