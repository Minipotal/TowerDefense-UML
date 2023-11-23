#pragma once

#include "Vect.h"

class GameObject
{
private:
	sf::Shape* _shape;

protected:
	float _color;
	int _speed;
	int _life;
	Vect2 _pos;
	Vect2 _size;

public:
	GameObject(Vect2 pos, Vect2 size, float color, int speed, int life);
	GameObject(Vect2 pos, float rayon, float color, int speed, int life);

	void minusHp(int number);
	void move(Vect2 direction);

	Vect2 pos();
	Vect2 size();

	void SetPosition(Vect2 pos);
	void SetOrigin(Vect2 pos);

	bool isPointInside(const sf::Vector2i& mousePos);
	Shape* getShape();

	virtual void ChooseTarget(std::vector<GameObject*> vEnnemiesList);
	virtual const std::vector<GameObject*>& GetBulletsList();

	virtual void Movement(float deltaTime);
};

