#include "Bullets.h"
#include "Vect.h"
#include "Towers.h"
#include <SFML/Graphics/Color.hpp>

Bullets::Bullets(Towers* pTower, Vect2 vPos, float fDiametre, int iDamage, sf::Color cColor) : GameObject(vPos, fDiametre, cColor)
{
	_pTower = pTower;
	_iDamage = iDamage;
}

void Bullets::Movement(float fDeltaTime, sf::RenderWindow* pWindow)
{
	sf::Vector2i vMousePos = sf::Mouse::getPosition(*pWindow);

	Vect2 vDirection;
	vDirection.setX(vMousePos.x - _vPos.x());
	vDirection.setY(vMousePos.y - _vPos.y());

	float fNorme = sqrt((vDirection.x() * vDirection.x()) + (vDirection.y() * vDirection.y()));

	vDirection.setX(vDirection.x() / fNorme);
	vDirection.setY(vDirection.y() / fNorme);

	Vect2 vNewPos;
	vNewPos.setX(_vPos.x() + (vDirection.x() * 350) * fDeltaTime);
	vNewPos.setY(_vPos.y() + (vDirection.y() * 350) * fDeltaTime);
	SetPosition(vNewPos);
}

/*void Bullets::EnnemieColid(GameObject* pEnemie)
{
	Vect2 vDistance = pEnemie->GetPosition() - _vPos;

	float fNorme = sqrt((vDistance.x() * vDistance.x()) + (vDistance.y() * vDistance.y()));

	if (fNorme < (_vSize.x() + pEnemie->GetSize().x()))
	{
		_pTower->RemoveFromBulletsList(this);
		pEnemie->minusHp(_iDamage);
		delete(this);
	}
}*/