#include "SpaceUtils.h"

std::string SpaceUtils::humanReadableDistance(unsigned long long distance)
{
	if(distance > AU)
	{
		double d = distance / AU;
		return StringUtils::format("%.2f AU", d);
	}
	else if(distance > KM_TRIGGER)
	{
		double d = distance / KM;
		return StringUtils::format("%.2f KM", d);
	}
	else
	{
		return StringUtils::format("%i M", distance);
	}
}
