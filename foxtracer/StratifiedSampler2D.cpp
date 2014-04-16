#include "StratifiedSampler2D.h"

StratifiedSampler2D::~StratifiedSampler2D(void)
{
}

Sample2D StratifiedSampler2D::getNextSample()
{
	Sample2D returnme;
	returnme.x = static_cast<float>(this->strataposx) * this->RNGDistributionX.max() + this->RNGDistributionX(*this->pRNGEngine);
	returnme.y = static_cast<float>(this->strataposy) * this->RNGDistributionY.max() + this->RNGDistributionY(*this->pRNGEngine);

	//Update strataposx/y
	strataposx++;
	if (strataposx == stratax)
	{
		strataposx = 0;
		strataposy++;
		if (strataposy == stratay)
		{
			strataposy = 0;
		}
	}

	return returnme;
}