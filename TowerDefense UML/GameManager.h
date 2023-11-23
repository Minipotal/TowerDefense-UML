#pragma once
#include <vector>
#include "Ennemies.h"

class Ressources;

class GameManager
{
private:

public:

	std::vector<Ennemies*> EnemiesList;

	GameManager();

	Ressources* _ressources;
};

