#include "Color.h"

void Color::SetRedComponent(const float& redComponentToSet) {
	this->redComponent = clamp(redComponentToSet);
}

void Color::SetGreenComponent(const float& greenComponentToSet) {
	this->greenComponent = clamp(greenComponentToSet);
}

void Color::SetBlueComponent(const float& blueComponentToSet) {
	this->blueComponent = clamp(blueComponentToSet);
}

float Color::clamp(float floatToClamp) {
	if (floatToClamp > 255) {
		return 1;
	}
	else if (floatToClamp < 0) {
		return 0;
	}
	else if (floatToClamp >= 0 && floatToClamp <= 1) {
		return floatToClamp;
	}
	else {
		return floatToClamp / 255;
	}
}
