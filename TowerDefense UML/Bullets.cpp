#include "Bullets.h"
#include "Math.h"

Bullets::Bullets(Towers* pTower, Vect2 pos, float fDiametre, int iDamage, float color) : GameObject(pos, fDiametre, color, 1, 1)
{
	_tower = pTower;
	_damage = iDamage;
}

void Bullets::Movement(float fDeltaTime)
{
	Vect2 vTargetPos = _target->pos();

	Vect2 vDirection;
	vDirection.setX(vTargetPos.x() - _pos.x());
	vDirection.setY(vTargetPos.y() - _pos.y());

	float fNorme = sqrt((vDirection.x() * vDirection.x()) + (vDirection.y() * vDirection.y()));

	vDirection.setX(vDirection.x() / fNorme);
	vDirection.setY(vDirection.y() / fNorme);

	Vect2 vNewPos;
	vNewPos.setX(_pos.x() + (vDirection.x() * 350) * fDeltaTime);
	vNewPos.setY(_pos.y() + (vDirection.y() * 350) * fDeltaTime);
	SetPosition(vNewPos);
}

void Bullets::EnnemiesColid(std::vector<GameObject*> vEnnemiesList)
{
	for (int i = 0; i < vEnnemiesList.size(); i++)
	{
		if (Math::CircleToCircleColid(_pos, _size.x(), vEnnemiesList[i]->pos(), vEnnemiesList[i]->size().x()) == true)
		{
			vEnnemiesList[i]->minusHp(_damage);
			_tower->RemoveFromBulletsList(this);
			delete(this);
		}
	}
	
}
