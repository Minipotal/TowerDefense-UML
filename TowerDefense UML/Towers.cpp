#include "Towers.h"

Towers::Towers(Vect2 pos, Vect2 size, float color, int damage, float cooldown, int range, int cost) : GameObject(pos, size, color, 0, 0) { };
Towers::Towers() : Towers({ 0, 0 }, { 0, 0 }, 0x000000, 0, 0, 0, 0) { };

int Towers::getCost()
{
    return 0;
}

void Towers::fire()
{

}
void Towers::levelUp()
{

}