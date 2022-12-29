#pragma once
#include "GL/freeglut.h"
#include "Solid.h"

class Triangle : public Solid
{
private:
	Vector3D ver1;
	Vector3D ver2;
	Vector3D ver3;

	Color color1;
	Color color2;
	Color color3;

	Vector3D norm1;
	Vector3D norm2;
	Vector3D norm3;

public:

	Triangle(Vector3D pVer1, Vector3D pVer2, Vector3D pVer3, Color pColor1, Color pColor2, Color pColor3, 
			 Vector3D pNorm1, Vector3D pNorm2, Vector3D pNorm3) :

		ver1(pVer1),
		ver2(pVer2),
		ver3(pVer3),

		color1(pColor1),
		color2(pColor2),
		color3(pColor3),

		norm1(pNorm1),
		norm2(pNorm2),
		norm3(pNorm3)
	{}

	Triangle(Vector3D pVer1, Vector3D pVer2, Vector3D pVer3,
		Vector3D pNorm1, Vector3D pNorm2, Vector3D pNorm3) :

		ver1(pVer1),
		ver2(pVer2),
		ver3(pVer3),

		color1(0.2),
		color2(0.2),
		color3(0.2),

		norm1(pNorm1),
		norm2(pNorm2),
		norm3(pNorm3)
	{}

	void Render();

	inline Vector3D GetVer1Pos() const { return this->ver1; }
	inline Vector3D GetVer2Pos() const { return this->ver2; }
	inline Vector3D GetVer3Pos() const { return this->ver3; }

	inline Color GetVer1Color() const { return this->color1; }
	inline Color GetVer2Color() const { return this->color2; }
	inline Color GetVer3Color() const { return this->color3; }

	inline Vector3D GetVer1Normal() const { return this->norm1; }
	inline Vector3D GetVer2Normal() const { return this->norm2; }
	inline Vector3D GetVer3Normal() const { return this->norm3; }

	inline  void SetVer1Pos(Vector3D& ver1ToSet) { this->ver1 = ver1ToSet; }
	inline  void SetVer2Pos(Vector3D& ver2ToSet) { this->ver2 = ver2ToSet; }
	inline  void SetVer3Pos(Vector3D& ver3ToSet) { this->ver3 = ver3ToSet; }

	inline void SetVer1Color(Color& color1ToSet) { this->color1 = color1ToSet; }
	inline void SetVer2Color(Color& color2ToSet) { this->color2 = color2ToSet; }
	inline void SetVer3Color(Color& color3ToSet) { this->color3 = color3ToSet; }

	inline void SetVer1Normal(Vector3D& norm1ToSet) { this->norm1 = norm1ToSet; }
	inline void SetVer2Normal(Vector3D& norm2ToSet) { this->norm2 = norm2ToSet; }
	inline void SetVer3Normal(Vector3D& norm3ToSet) { this->norm3 = norm3ToSet; }
};

