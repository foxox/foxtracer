#include "HammerslyScrambledSampler2D.h"

HammerslyScrambledSampler2D::~HammerslyScrambledSampler2D(void)
{
}

Sample2D HammerslyScrambledSampler2D::getNextSample()
{
	Sample2D returnme;
	//returnme.x = static_cast<float>(this->samplenum) / static_cast<float>(this->numSamples);
	returnme.x = static_cast<float>(xshufflehammersly[this->samplenum]) / static_cast<float>(this->numSamples);
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