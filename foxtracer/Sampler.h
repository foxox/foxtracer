#pragma once

//#include "Sample.h"
//#include <vector>

#include "FloatRange.h"

#include "common.h"

#include <Random>

using namespace std;

class Sampler
{
protected:
	const size_t numSamples;
	//RNG
	std::default_random_engine* pRNGEngine;

public:
	//Sampler();
	Sampler(size_t _numSamples, std::default_random_engine* _rng);
	virtual ~Sampler(void);

	//virtual Sample getNextSample() = 0;
	//virtual vector<Sample> getNextSampleBatch() = 0;

	virtual size_t getNumSamples();
};


//Radical Inverse
//Based on implementation in Physically Based Rendering by Matt Pharr and Greg Humphreys, Second Edition
inline double radicalInverse(int n, int base)
{
#if _DEBUG
	if (base == 1)
		throw new invalid_argument("Radical inverse base cannot be 1 with this implementation.");
#endif

	double val = 0;
	double invBase = 1.0 / static_cast<double>(base);
	double invBi = invBase;
	while (n > 0)
	{
		int d_i = (n % base);
		val += d_i * invBi;
		n = static_cast<int>(static_cast<float>(n)* invBase);
		//n *= invBase;
		invBi *= invBase;
	}
	return val;
}

//VanDerCorput sequence computation
inline float VanDerCorput(uint32_t n, uint32_t scramble)
{
	//reverse bits of n
	n = (n << 16) | (n >> 16);
	n = ((n & 0x00ff00ff) << 8) | ((n & 0xff00ff00) >> 8);
	n = ((n & 0x0f0f0f0f) << 4) | ((n & 0xf0f0f0f0) >> 4);
	n = ((n & 0x33333333) << 2) | ((n & 0xcccccccc) >> 2);
	n = ((n & 0x55555555) << 1) | ((n & 0xaaaaaaaa) >> 1);

	n ^= scramble;
	return ((n >> 8) & 0xffffff) / static_cast<float>(1 << 24);
}
