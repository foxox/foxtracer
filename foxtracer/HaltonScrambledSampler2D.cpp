#include "HaltonScrambledSampler2D.h"

HaltonScrambledSampler2D::~HaltonScrambledSampler2D(void)
{
}

Sample2D HaltonScrambledSampler2D::getNextSample()
{
	Sample2D returnme;
	returnme.x = static_cast<float>(radicalInverseShuffled(this->samplenum, xprime, xshuffle));
	returnme.y = static_cast<float>(radicalInverseShuffled(this->samplenum, yprime, yshuffle));

	//Scale 0->1 samples to sampleRangeX/Y
	returnme.x *= (this->sampleRangeX.high - this->sampleRangeX.low);
	returnme.y *= (this->sampleRangeY.high - this->sampleRangeY.low);
	returnme.x += this->sampleRangeX.low;
	returnme.y += this->sampleRangeY.low;

	//increment sample counter
	this->samplenum++;

	return returnme;
}