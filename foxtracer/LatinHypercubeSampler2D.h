#pragma once
#include "Sampler2D.h"

class LatinHypercubeSampler2D :
	public Sampler2D
{
protected:
	//shuffle state
	size_t* const xshuffle;	//note that it's not "const size_t*"
	size_t* const yshuffle;
	size_t samplenum;

public:
	LatinHypercubeSampler2D(void);
	LatinHypercubeSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY) :
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		xshuffle(new size_t[numSamples]), yshuffle(new size_t[numSamples]),
		samplenum(0)
	{
		//init distributions
		this->RNGDistributionX =
			uniform_real_distribution<float>(0,
			(sampleRangeX.high - sampleRangeX.low) / static_cast<float>(numSamples));
		this->RNGDistributionY =
			uniform_real_distribution<float>(0,
			(sampleRangeY.high - sampleRangeY.low) / static_cast<float>(numSamples));

		reinitialize();
	}
	virtual ~LatinHypercubeSampler2D(void);

	virtual void reinitialize()
	{
		samplenum = 0;

		//init shuffle
		for (size_t i = 0; i < numSamples; i++)
		{
			xshuffle[i] = i;
			yshuffle[i] = i;
		}

		//do shuffle
		//uniform_int_distribution<int> dist;
		uniform_int_distribution<int> dist(0, numSamples - 1);
		for (size_t i = 0; i < numSamples; i++)
		{
			//size_t newspot = i + (dist(*this->pRNGEngine) % (numSamples - i));	//swap with a higher one
			//swap(xshuffle[i], xshuffle[newspot]);

			//newspot = i + (dist(*this->pRNGEngine) % (numSamples - i));	//swap with a higher one
			//swap(yshuffle[i], yshuffle[newspot]);

			size_t newspot = dist(*this->pRNGEngine);
			swap(xshuffle[i], xshuffle[newspot]);

			newspot = dist(*this->pRNGEngine);
			swap(yshuffle[i], yshuffle[newspot]);
		}
	}

	virtual Sample2D getNextSample();
};

