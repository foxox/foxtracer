#pragma once

#include "Sample.h"
#include <vector>

using namespace std;

class Sampler
{
public:
	Sampler(void);
	virtual ~Sampler(void);

	virtual Sample getSample() = 0;
	virtual vector<Sample> getSampleBatch() = 0;
};

