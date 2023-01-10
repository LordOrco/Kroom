#pragma once
#include "Vector3D.h"
#include <GL/glut.h>
#include "Color.h"

class Solid
{
private:
	Vector3D coordinates;
	Vector3D speed;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Color color;

public:

	Solid() :
		coordinates(Vector3D(0, 0, 0)),
		speed(0),
		orientation(0),
		orientationSpeed(0),
		color()
	{}

	Solid(Vector3D positionArgument, Vector3D orientationArgument, Color colorArgument, Vector3D speedArgument, Vector3D orientationSpeedArgument) :
		coordinates(positionArgument),

		orientation(orientationArgument),

		speed(speedArgument),

		orientationSpeed(orientationSpeedArgument),

		color(colorArgument)
	{}

	Solid(Vector3D positionArgument) :
		coordinates(positionArgument),

		orientation(0),

		speed(0),

		orientationSpeed(0),

		color()
	{}

	Solid(Vector3D positionArgument, Vector3D orientationArgument, Color colorArgument) :
		coordinates(positionArgument),
		orientation(orientationArgument),
		speed(0),
		orientationSpeed(0),
		color(colorArgument)
	{}


	//GETTERS
	inline Vector3D GetCoordinates() const { return this->coordinates; }
	inline Vector3D GetSpeed() const { return this->speed; }
	inline Vector3D GetOrientation() const { return this->orientation; }
	inline Vector3D GetRotationSpeed() const { return this->orientationSpeed; }
	inline Color GetColor() const { return this->color; }

	inline float GetCoordinateX() const { return this->coordinates.GetX(); }
	inline float GetCoordinateY() const { return this->coordinates.GetY(); }
	inline float GetCoordinateZ() const { return this->coordinates.GetZ(); }

	inline float GetSpeedX() const { return this->speed.GetX(); }
	inline float GetSpeedY() const { return this->speed.GetY(); }
	inline float GetSpeedZ() const { return this->speed.GetZ(); }

	inline float GetRotX() const { return this->orientation.GetX(); }
	inline float GetRotY() const { return this->orientation.GetY(); }
	inline float GetRotZ() const { return this->orientation.GetZ(); }

	inline float GetRotSpeedX() const { return this->orientationSpeed.GetX(); }
	inline float GetRotSpeedY() const { return this->orientationSpeed.GetY(); }
	inline float GetRotSpeedZ() const { return this->orientationSpeed.GetZ(); }

	inline float GetRedComponent() const { return this->color.GetRedComponent(); }
	inline float GetGreenComponent() const { return this->color.GetGreenComponent(); }
	inline float GetBlueComponent() const { return this->color.GetBlueComponent(); }


	//SETTERS
	inline void SetCoordinates(const Vector3D& coordinatesToSet) { this->coordinates = coordinatesToSet; }
	inline void SetSpeed(const Vector3D& speedToSet) { this->speed = speedToSet; }
	inline void SetOrientation(const Vector3D& orientationToSet) { this->orientation = orientationToSet; }
	inline void SetRotationSpeed(const Vector3D& rotSpeedToSet) { this->orientationSpeed = rotSpeedToSet; }
	inline void SetColor(const Color& colorToSet) { this->color = colorToSet; }

	inline void SetCoordinateX(const float& coordinateXToSet) { this->coordinates.SetX(coordinateXToSet); }
	inline void SetCoordinateY(const float& coordinateYToSet) { this->coordinates.SetY(coordinateYToSet); }
	inline void SetCoordinateZ(const float& coordinateZToSet) { this->coordinates.SetZ(coordinateZToSet); }

	inline void SetSpeedX(const float& SpeedXToSet) { this->speed.SetX(SpeedXToSet); }
	inline void SetSpeedY(const float& SpeedYToSet) { this->speed.SetY(SpeedYToSet); }
	inline void SetSpeedZ(const float& SpeedZToSet) { this->speed.SetZ(SpeedZToSet); }

	inline void SetRotX(const float& rotXToSet) { this->orientation.SetX(rotXToSet); }
	inline void SetRotY(const float& rotYToSet) { this->orientation.SetY(rotYToSet); }
	inline void SetRotZ(const float& rotZToSet) { this->orientation.SetZ(rotZToSet); }

	inline void SetRotSpeedX(const float& rotSpeedXToSet) { this->orientationSpeed.SetX(rotSpeedXToSet); }
	inline void SetRotSpeedY(const float& rotSpeedYToSet) { this->orientationSpeed.SetY(rotSpeedYToSet); }
	inline void SetRotSpeedZ(const float& rotSpeedZToSet) { this->orientationSpeed.SetZ(rotSpeedZToSet); }

	inline void SetRedComponent(const float& redComponentToSet) { this->color.SetRedComponent(redComponentToSet); }
	inline void SetGreenComponent(const float& greenComponentToSet) { this->color.SetGreenComponent(greenComponentToSet); }
	inline void SetBlueComponent(const float& blueComponentToSet) { this->color.SetBlueComponent(blueComponentToSet); }

	//M�TODOS
	virtual void Render() = 0;
	virtual void Update();
};

