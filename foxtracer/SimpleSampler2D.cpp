#include "SimpleSampler2D.h"


//SimpleSampler2D::SimpleSampler2D(void)
//{
//}


SimpleSampler2D::~SimpleSampler2D(void)
{
}

Sample2D SimpleSampler2D::getNextSample()
{
	Sample2D returnme;
	returnme.x = /*static_cast<float>(*/this->RNGDistributionX(*this->pRNGEngine);
	returnme.y = /*static_cast<float>(*/this->RNGDistributionY(*this->pRNGEngine);
	return returnme;
}