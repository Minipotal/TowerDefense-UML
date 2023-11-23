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
	Vect2 vTargetPos = _pTarget->GetPosition();

	Vect2 vDirection;
	vDirection.setX(vTargetPos.x() - _vPos.x());
	vDirection.setY(vTargetPos.y() - _vPos.y());

	float fNorme = sqrt((vDirection.x() * vDirection.x()) + (vDirection.y() * vDirection.y()));

	vDirection.setX(vDirection.x() / fNorme);
	vDirection.setY(vDirection.y() / fNorme);

	Vect2 vNewPos;
	vNewPos.setX(_vPos.x() + (vDirection.x() * 350) * fDeltaTime);
	vNewPos.setY(_vPos.y() + (vDirection.y() * 350) * fDeltaTime);
	SetPosition(vNewPos);
}
