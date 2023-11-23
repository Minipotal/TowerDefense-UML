#include "Math.h"
#include "Vect.h"

namespace Math
{
	bool CircleToCircleColid(Vect2 vPosA, float fDiameterA, Vect2 vPosB, float fDiameterB)
	{
		Vect2 vDistance = vPosA - vPosB;

		float fNorme = sqrt((vDistance.x() * vDistance.x()) + (vDistance.y() * vDistance.y()));

		if (fNorme < (fDiameterA/2 + fDiameterB))
			return true;
		else
			return false;
	}
}