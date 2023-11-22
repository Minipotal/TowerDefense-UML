#pragma once
#include "GameObject.h"
#include "Bullets.h"

class Towers : public GameObject
{
private:
	std::vector<Bullets*> _vBulletsList;
	int id;
	int _iDamage;
	int _iRange;
	int _iCost;
	sf::Color _cColor;
	float _fCooldown;
	sf::Clock _oClock;

public:
	Towers(Vect2 vPos, Vect2 vSize, sf::Color cColor);
	void ShootBullet();

	//Ball Gestion
	const std::vector<Bullets*>& GetBulletsList() const;
	void RemoveFromBulletsList(Bullets* pBullets);

	int GetCost();
	void LevelUp();
};