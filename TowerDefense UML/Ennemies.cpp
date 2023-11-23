#include "Ennemies.h"
#include <ctime>
#include <cstdlib>
#include<SFML/Graphics/Color.hpp>

Ennemies::Ennemies(Vect2 vPos, float fDiameter, int iLife) : GameObject(vPos, fDiameter, sf::Color::Red)
{
	_iLife = 5;
}
