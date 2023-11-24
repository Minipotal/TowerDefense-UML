#pragma once
#include "GameObject.h"

namespace Math
{
	bool TowerRangeCheck(Vect2 towerPos, Vect2 towerSize, int towerRange, Vect2 ennemiePos, Vect2 ennemieSize);
	bool BulletsToEnnemiesColid(Vect2 bulletPos, Vect2 bulletSize, Vect2 ennemiePos, Vect2 ennemieSize);
};