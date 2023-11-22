#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;

class Vect2
{
private:
	float _x;
	float _y;
	bool abs;

public:
	Vect2();
	Vect2(bool abs);
	Vect2(float x, float y);
	Vect2(float x, float y, bool abs);
	void setIfOnlyInAbs(bool abs);
	float x();
	float y();
	void setX(float x);
	void setY(float y);

	float norme();
	Vect2 normal();
	void normalize();
	float getAngle();

	Vector2u getVector2u();
	Vector2f getVector2f();
	VideoMode getVideoMode();

	Vect2 operator*(float val);
	Vect2 operator/(float val);
	float operator*(Vect2 otherVect2);
	Vect2 operator+(Vect2 otherVect2);
	Vect2 operator-(Vect2 otherVect2);

	void operator=(Vect2 otherVect2);

	void operator*=(float val);
	void operator/=(float val);
	void operator+=(Vect2 otherVect2);
	void operator-=(Vect2 otherVect2);
	void operator++();
	void operator--();

private:
	void makeAbsolute();
};