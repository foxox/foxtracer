#pragma once
#include "sampler2d.h"
class StratifiedSampler2D :
	public Sampler2D
{
protected:
	//Stratification state
	const size_t stratax;
	const size_t stratay;

	size_t strataposx;
	size_t strataposy;

public:
	StratifiedSampler2D(void);
	StratifiedSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY,
		size_t _stratax, size_t _stratay) :
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		stratax(_stratax), stratay(_stratay),
		strataposx(0), strataposy(0)
	{
		this->RNGDistributionX =
			uniform_real_distribution<float>(0,
			(sampleRangeX.high - sampleRangeX.low) / static_cast<float>(stratax));
		this->RNGDistributionY =
			uniform_real_distribution<float>(0,
			(sampleRangeY.high - sampleRangeY.low) / static_cast<float>(stratay));
	}
	virtual ~StratifiedSampler2D(void);

	virtual void reinitialize()
	{
		strataposx = 0;
		strataposy = 0;
	}

	virtual Sample2D getNextSample();
};

