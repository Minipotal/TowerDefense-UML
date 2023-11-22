#pragma once
#include "Vect.h"

class GameObject
{
private:
	sf::Shape* _pShape;
protected:
	Vect2 _vPos;
	Vect2 _vSize;
	int _iSpeed;
	int _iLife;

public:
//Tower Methods
	GameObject(Vect2 vPos, float fDiametre, sf::Color cColor); //cercle
	GameObject(Vect2 vPos, Vect2 vSize, sf::Color cColor); //Rect

	void Draw(sf::RenderWindow* pWindow);

	Vect2 GetPosition();
	void SetPosition(Vect2 vPos);

	Vect2 GetSize();
	void SetOrigine(Vect2 vPos);


//Other 
	void minusHp(int number);
	void move(Vect2 direction);
};

