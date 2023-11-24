#include "Math.h"
#include "Vect.h"

namespace Math
{
	bool CircleToCircleColid(Vect2 posCircle1, float fDiameterCircle1, Vect2 posCircle2, float fDiameterCircle2)
	{
		Vect2 posA;
		posA.setX(posCircle1.x() + fDiameterCircle1 / 2);
		posA.setY(posCircle1.y() + fDiameterCircle1 / 2);

		Vect2 posB;
		posB.setX(posCircle2.x() + fDiameterCircle2 / 2);
		posB.setY(posCircle2.y() + fDiameterCircle2 / 2);

		Vect2 vDistance = posA - posB;

		float fNorme = sqrt((vDistance.x() * vDistance.x()) + (vDistance.y() * vDistance.y()));

		if (fNorme < (fDiameterCircle1 / 2 + fDiameterCircle2 / 2))
			return true;
		else
			return false;
	}
}