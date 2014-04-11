#pragma once

//#include "Sample.h"
//#include <vector>

#include "FloatRange.h"

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
};

