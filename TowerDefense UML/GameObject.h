#pragma once
#include "Vect.h"

class GameObject
{
private:
	sf::Shape* _pShape;
protected:
	float _color;
	int _speed;
	int _life;
	Vect2 _pos;
	Vect2 _size;

public:
	GameObject(Vect2 vPos, float fDiametre, sf::Color cColor); //cercle
	GameObject(Vect2 vPos, Vect2 vSize, sf::Color cColor); //Rect

	void Draw(sf::RenderWindow* pWindow);

	Vect2 GetPosition();
	void SetPosition(Vect2 vPos);

	Vect2 GetSize();
	void SetOrigine(Vect2 vPos);

	void minusHp(int number);
	void move(Vect2 direction);

	Vect2 pos();
	Vect2 size();

	bool isPointInside(const sf::Vector2i& mousePos);
	Shape* getShape();
};

