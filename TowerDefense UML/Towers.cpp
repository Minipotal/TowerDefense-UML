#include "Towers.h"

Towers::Towers(Vect2 pos, Vect2 size, float color, int damage, float cooldown, int range, int cost, int bulletSpeed) : GameObject(pos, size, color, 0, 0) {};
Towers::Towers() : Towers({ 0, 0 }, { 0, 0 }, 0x000000, 0, 0, 0, 0, 0) { };

int Towers::getCost()
{
    return _cost;
}

void Towers::fire()
{

}
void Towers::levelUp()
{

}