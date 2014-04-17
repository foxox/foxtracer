#include "LatinHypercubeSampler2D.h"

LatinHypercubeSampler2D::~LatinHypercubeSampler2D(void)
{
	delete[] this->xshuffle;
	delete[] this->yshuffle;
}

Sample2D LatinHypercubeSampler2D::getNextSample()
{
	Sample2D returnme;
	returnme.x = this->RNGDistributionX(*this->pRNGEngine);
	returnme.y = this->RNGDistributionY(*this->pRNGEngine);
	//add on next shuffled position
	returnme.x += this->RNGDistributionX.max() * this->xshuffle[this->samplenum];
	returnme.y += this->RNGDistributionY.max() * this->yshuffle[this->samplenum];
	//increment sample counter
	this->samplenum++;

	return returnme;
}