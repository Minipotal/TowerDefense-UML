#pragma once

#include "GameObject.h"

class Bullets;
class Ennemies;

typedef enum TowersStates
{
	Idle, Targeting
};

class Towers : public GameObject
{
private:
	int _state;
	int _damage;
	float _cooldown;
	int _range;
	int _cost;
	int _bulletSpeed;
	GameObject* _pTarget;
	sf::Clock _oClock;
	std::vector<GameObject*> _vBulletsList;

public:
	Towers(Vect2 pos, Vect2 size, MyColor color, int damage, float cooldown, int range, int cost, int bulletSpeed);
	Towers();

	int getCost();
	void levelUp(int damage);

	void ChooseTarget(std::vector<GameObject*> vEnnemiesList) override;

	void StateMachine() override;

	//Ball Gestion
	const std::vector<GameObject*>& GetBulletsList() override ;
	void RemoveFromBulletsList(GameObject* pBullets);
};