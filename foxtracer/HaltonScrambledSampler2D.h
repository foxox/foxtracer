#pragma once
#include "Sampler2d.h"

class HaltonScrambledSampler2D :
	public Sampler2D
{
protected:
	size_t samplenum;

	static const int xprime = 3;
	static const int yprime = 2;

	size_t* const xshuffle;
	size_t* const yshuffle;

	//Based on implementation in Physically Based Rendering by Matt Pharr and Greg Humphreys, Second Edition 
	inline void GeneratePermutation(uint32_t *buf, uint32_t b)
	{
		for (uint32_t i = 0; i < b; ++i)
			buf[i] = i;
		//Shuffle(buf, b, 1, rng);

		//do shuffle
		uniform_int_distribution<int> dist(0, b - 1);
		for (size_t i = 0; i < b; i++)
		{
			size_t newspot = dist(*this->pRNGEngine);
			swap(buf[i], buf[newspot]);
		}
	}

public:
	HaltonScrambledSampler2D(void);
	HaltonScrambledSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY) :
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		samplenum(0),
		xshuffle(new size_t[xprime]), yshuffle(new size_t[yprime])
	{
		GeneratePermutation(xshuffle, xprime);
		GeneratePermutation(yshuffle, yprime);
	}
	virtual ~HaltonScrambledSampler2D(void);

	virtual void reinitialize()
	{
		samplenum = 0;
		GeneratePermutation(xshuffle, xprime);
		GeneratePermutation(yshuffle, yprime);
	}

	virtual Sample2D getNextSample();

};