#pragma once
#include "sampler.h"

#include "Sample2D.h"

class Sampler2D :
	public Sampler
{
protected:
	FloatRange sampleRangeX;
	FloatRange sampleRangeY;

	std::uniform_real_distribution<float> RNGDistributionX;
	std::uniform_real_distribution<float> RNGDistributionY;

	static const bool shouldReinitializeIfOversampled = true;

public:
	//Sampler2D(void);
	Sampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX,
		FloatRange sampleRangeY) :
		Sampler(numSamples, _pRNGEngine),
		sampleRangeX(sampleRangeX),
		sampleRangeY(sampleRangeY),
		RNGDistributionX(sampleRangeX.low, sampleRangeX.high),
		RNGDistributionY(sampleRangeY.low, sampleRangeY.high) {}
	virtual ~Sampler2D(void);

	virtual void reinitialize() = 0;

	virtual Sample2D getNextSample() = 0;
};

