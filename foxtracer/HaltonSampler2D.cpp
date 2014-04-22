#include "HaltonSampler2D.h"

HaltonSampler2D::~HaltonSampler2D(void)
{
}

Sample2D HaltonSampler2D::getNextSample()
{
	Sample2D returnme;
	returnme.x = static_cast<float>(radicalInverse(this->samplenum, 3));
	returnme.y = static_cast<float>(radicalInverse(this->samplenum, 2));

	//Scale 0->1 samples to sampleRangeX/Y
	returnme.x *= (this->sampleRangeX.high - this->sampleRangeX.low);
	returnme.y *= (this->sampleRangeY.high - this->sampleRangeY.low);
	returnme.x += this->sampleRangeX.low;
	returnme.y += this->sampleRangeY.low;

	//increment sample counter
	this->samplenum++;

	return returnme;
}