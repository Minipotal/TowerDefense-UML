#include "Ressources.h"

Ressources::Ressources(int gold, int wood, int iron)
{
	_gold = gold;
	_wood = wood;
	_iron = iron;
}

Ressources::Ressources() : Ressources(50000, 0, 0) {};

void Ressources::setGold(int gold)
{
	_gold += gold;
}

void Ressources::setWood(int wood)
{
	_wood += wood;
}

void Ressources::setIron(int iron)
{
	_iron += iron;
}
