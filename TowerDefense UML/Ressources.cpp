#include "Ressources.h"

Ressources::Ressources(int gold, int wood, int iron)
{
	_gold = gold;
	_wood = wood;
	_iron = iron;
}

Ressources::Ressources() : Ressources(50000, 0, 0) {};
