#include "DartThresholdSampler2D.h"


DartThresholdSampler2D::~DartThresholdSampler2D(void)
{
}

Sample2D DartThresholdSampler2D::getNextSample()
{
	Sample2D returnme;
	returnme.x = this->RNGDistributionX(*this->pRNGEngine);
	returnme.y = this->RNGDistributionY(*this->pRNGEngine);
	return returnme;
}