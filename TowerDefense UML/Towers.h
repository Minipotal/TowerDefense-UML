#pragma once
#include "GameObject.h"
#include "Bullets.h"
#include "Ennemies.h"

typedef enum TowersStates
{
	Idle,Targeting
};

class Towers : public GameObject
{
private:
	int _iState;
	std::vector<Bullets*> _vBulletsList;
	int id;
	int _iDamage;
	int _iRange;
	int _iCost;
	Ennemies* _pTarget;
	sf::Color _cColor;
	float _fCooldown;
	sf::Clock _oClock;

public:
	Towers(Vect2 vPos, Vect2 vSize, sf::Color cColor);
	void ChooseTarget(std::vector<Ennemies*> vEnnemiesList);

	void StateMachine();

	//Ball Gestion
	const std::vector<Bullets*>& GetBulletsList() const;
	void RemoveFromBulletsList(Bullets* pBullets);

	int GetCost();


// public:
// 	Towers(Vect2 pos, Vect2 size, float color, int damage, float cooldown, int range, int cost, int bulletSpeed);
// 	Towers();

};