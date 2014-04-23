#include "VanDerCorputSobolSampler2D.h"

VanDerCorputSobolSampler2D::~VanDerCorputSobolSampler2D(void)
{
}

Sample2D VanDerCorputSobolSampler2D::getNextSample()
{
	Sample2D returnme;

	returnme.x = static_cast<float>(VanDerCorput(this->samplenum, 0));
	//equivalent to...
	//returnme.x = static_cast<float>(VanDerCorput2(this->samplenum));
	//equivalent to...
	//returnme.x = static_cast<float>(radicalInverse(this->samplenum, 2));

	returnme.y = static_cast<float>(Sobol2(this->samplenum, 0));

	//Scale 0->1 samples to sampleRangeX/Y
	returnme.x *= (this->sampleRangeX.high - this->sampleRangeX.low);
	returnme.y *= (this->sampleRangeY.high - this->sampleRangeY.low);
	returnme.x += this->sampleRangeX.low;
	returnme.y += this->sampleRangeY.low;

	//increment sample counter
	this->samplenum++;

	return returnme;
}