#include "SimpleSampler2D.h"


SimpleSampler2D::~SimpleSampler2D(void)
{
}

Sample2D SimpleSampler2D::getNextSample()
{
	Sample2D returnme;
	returnme.x = this->RNGDistributionX(*this->pRNGEngine);
	returnme.y = this->RNGDistributionY(*this->pRNGEngine);
	return returnme;
}