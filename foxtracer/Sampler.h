#pragma once

#include "Sample.h"
#include <vector>

using namespace std;

class Sampler
{
protected:
	const size_t numSamples;

public:
	Sampler();
	Sampler(size_t _numSamples);
	virtual ~Sampler(void);

	virtual Sample getNextSample() = 0;
	//virtual vector<Sample> getNextSampleBatch() = 0;
};

