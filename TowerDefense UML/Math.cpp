#include "Math.h"
#include "Vect.h"

namespace Math
{
	bool TowerRangeCheck(Vect2 towerPos, Vect2 towerSize, int towerRange, Vect2 ennemiePos, Vect2 ennemieSize)
	{
		Vect2 posA;
		posA.setX(towerPos.x() + towerSize.x() / 2);
		posA.setY(towerPos.y() + towerSize.y() / 2);

		Vect2 posB;
		posB.setX(ennemiePos.x() + ennemieSize.x() / 2);
		posB.setY(ennemiePos.y() + ennemieSize.y() / 2);

		Vect2 vDistance = posB - posA;

		float fNorme = sqrt((vDistance.x() * vDistance.x()) + (vDistance.y() * vDistance.y()));

		if (fNorme < (towerRange + ennemieSize.x() / 2))
			return true;
		else
			return false;
	}

	bool BulletsToEnnemiesColid(Vect2 bulletPos, Vect2 bulletSize, Vect2 ennemiePos, Vect2 ennemieSize)
	{
		Vect2 posA;
		posA.setX(bulletPos.x() + bulletSize.x() / 2);
		posA.setY(bulletPos.y() + bulletSize.y() / 2);

		Vect2 posB;
		posB.setX(ennemiePos.x() + ennemieSize.x() / 2);
		posB.setY(ennemiePos.y() + ennemieSize.y() / 2);

		Vect2 vDistance = posB - posA;

		float fNorme = sqrt((vDistance.x() * vDistance.x()) + (vDistance.y() * vDistance.y()));

		if (fNorme < (bulletSize.x() / 2 + ennemieSize.x() / 2))
			return true;
		else
			return false;
	}
}