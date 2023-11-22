#include "GameObject.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

GameObject::GameObject(Vect2 vPos, float fDiametre, sf::Color cColor)//Circle
{
	_vPos = vPos;
	_vSize.setX(fDiametre);
	_vSize.setY(fDiametre);
	_pShape = new sf::CircleShape(fDiametre);
	_pShape->setOrigin(fDiametre / 2, fDiametre / 2);
	_pShape->setPosition(vPos.getVector2f());
	_pShape->setFillColor(cColor);
};
GameObject::GameObject(Vect2 vPos, Vect2 vSize, sf::Color cColor)//Rect
{
	_vPos = vPos;
	_vSize = vSize;
	_pShape = new sf::RectangleShape(vSize.getVector2f());
	_pShape->setOrigin(vPos.x() / 2, vPos.y() / 2);
	_pShape->setPosition(vPos.getVector2f());
	_pShape->setFillColor(cColor);
};

void GameObject::Draw(sf::RenderWindow* pWindow)
{
	pWindow->draw(*_pShape);
}
void GameObject::SetPosition(Vect2 vPos)
{
	_vPos = vPos;
	_pShape->setPosition(vPos.getVector2f());
}
void GameObject::SetOrigine(Vect2 vPos)
{
	_pShape->setOrigin(vPos.getVector2f());
}




/////////Tempo////////////////

void GameObject::minusHp(int number)
{
	_iLife -= number;
}

void GameObject::move(Vect2 direction)
{
	_vPos += direction;
}