#include "Bullets.h"
#include "Math.h"

Bullets::Bullets(Towers* pTower, Vect2 pos, float fDiametre, int iDamage, MyColor color, GameObject* pTarget) : GameObject(pos, fDiametre, color, 1, 1)
{
	_size = Vect2(fDiametre, fDiametre);
	_target = pTarget;
	_tower = pTower;
	_damage = iDamage;
}

void Bullets::Movement(float fDeltaTime)
{
	Vect2 vTargetPos = _target->pos();
	vTargetPos.setX(vTargetPos.x()+ _target->size().x()/2);
	vTargetPos.setY(vTargetPos.y() + _target->size().y()/2);

	Vect2 BulletsPos;
	BulletsPos.setX(_pos.x() + _size.x());
	BulletsPos.setY(_pos.y() + _size.y());

	Vect2 vDirection;
	vDirection.setX(vTargetPos.x() - BulletsPos.x());
	vDirection.setY(vTargetPos.y() - BulletsPos.y());

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
		if (vEnnemiesList[i]->GetLife() <= 0)
		{
			return;
		}
		if (Math::BulletsToEnnemiesColid(_pos, _size, vEnnemiesList[i]->pos(), vEnnemiesList[i]->size()) == true)
		{
			vEnnemiesList[i]->minusHp(_damage);
			_tower->RemoveFromBulletsList(this);
			delete(this);
		}

		
		
	}
	
}
