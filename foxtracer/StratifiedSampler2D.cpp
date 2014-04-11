#include "StratifiedSampler2D.h"

StratifiedSampler2D::~StratifiedSampler2D(void)
{
}

Sample2D StratifiedSampler2D::getNextSample()
{
	Sample2D returnme;
	returnme.x = /*static_cast<float>(*/this->RNGDistributionX(*this->pRNGEngine);
	returnme.y = /*static_cast<float>(*/this->RNGDistributionY(*this->pRNGEngine);
	return returnme;
}