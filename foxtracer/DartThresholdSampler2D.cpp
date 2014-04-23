#include "DartThresholdSampler2D.h"


DartThresholdSampler2D::~DartThresholdSampler2D(void)
{
}

Sample2D DartThresholdSampler2D::getNextSample()
{
	Sample2D returnme;
	float nearestDistanceSquared;
	size_t count = 0;
	const size_t MAXTRIALS = 5000;
	do
	{
		nearestDistanceSquared = FLT_MAX;

		returnme.x = this->RNGDistributionX(*this->pRNGEngine);
		returnme.y = this->RNGDistributionY(*this->pRNGEngine);

		for (size_t i = 0; i < this->samplenum; i++)
		{
			float sampleDistanceSquared =
				Sample2D::Sample2DDistanceSquared(this->samples[i], returnme);
			if (sampleDistanceSquared < nearestDistanceSquared)
				nearestDistanceSquared = sampleDistanceSquared;
		}
		count++;
	} while (this->samplenum != 0 && nearestDistanceSquared < this->threshold && count < MAXTRIALS);

	if (count >= MAXTRIALS)
		return Sample2D(0, 0);

	this->samples[this->samplenum] = returnme;

	this->samplenum++;
	return returnme;
}