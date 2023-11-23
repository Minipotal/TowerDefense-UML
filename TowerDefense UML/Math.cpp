#include "Math.h"
#include "Vect.h"

namespace Math
{
	bool CircleToCircleColid(Vect2 posCircle1, float fDiameterCircle1, Vect2 posCircle2, float fDiameterCircle2)
	{
		Vect2 vDistance = posCircle1 - posCircle2;

		float fNorme = sqrt((vDistance.x() * vDistance.x()) + (vDistance.y() * vDistance.y()));

		if (fNorme < (fDiameterCircle1 /2 + fDiameterCircle2))
			return true;
		else
			return false;
	}
}