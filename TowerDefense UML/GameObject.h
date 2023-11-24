#pragma once

#include "Vect.h"
#include "Colors.h"

class GameObject
{
private:
	sf::Shape* _shape;

protected:
	MyColor _color;
	int _speed;
	int _life;
	Vect2 _pos;
	Vect2 _size;

public:
	GameObject(Vect2 pos, Vect2 size, MyColor color, int speed, int life);
	GameObject(Vect2 pos, float rayon, MyColor color, int speed, int life);

	void minusHp(int number);
	void move(Vect2 direction, int speed, float deltaTime);

	Vect2 pos();
	Vect2 size();

	void SetPosition(Vect2 pos);
	void SetSize(Vect2 size);
	void SetOrigin(Vect2 pos);

	void SetBorderColor(sf::Color cColor);
	void SetShape(sf::Shape* newShape);

	bool isPointInside(const sf::Vector2i& mousePos);

	Shape* getShape();
	sf::Color getColor();
	int GetSpeed();

	virtual void ChooseTarget(std::vector<GameObject*> vEnnemiesList);
	virtual const std::vector<GameObject*>& GetBulletsList();

	virtual void Movement(float deltaTime);
	virtual int getDamage();
};

