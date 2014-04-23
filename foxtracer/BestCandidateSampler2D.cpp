#include "BestCandidateSampler2D.h"


BestCandidateSampler2D::~BestCandidateSampler2D(void)
{
}

Sample2D BestCandidateSampler2D::getNextSample()
{
	Sample2D returnme;

	map<float, Sample2D> candidates;

	//generate candidates
	for (size_t i = 0; i < this->numCandidates; i++)
	{
		Sample2D candidate;
		candidate.x = this->RNGDistributionX(*this->pRNGEngine);
		candidate.y = this->RNGDistributionY(*this->pRNGEngine);

		float candidateNearestDistanceSquared = FLT_MAX;

		//find its nearest distance to existing samples
		for (size_t j = 0; j < this->samplenum; j++)
		{
			float distance = Sample2D::Sample2DDistanceSquared(this->samples[j], candidate);
			if (distance < candidateNearestDistanceSquared)
				candidateNearestDistanceSquared = distance;
		}

		candidates[candidateNearestDistanceSquared] = candidate;
	}

	//find greatest distance candidate
	float greatestDistance = 0.0f;
	for (map<float, Sample2D>::iterator i = candidates.begin(); i != candidates.end(); i++)
	{
		float dist = i->first;
		if (dist > greatestDistance)
		{
			greatestDistance = dist;
			returnme = i->second;
		}
	}

	this->samples[this->samplenum] = returnme;

	this->samplenum++;
	return returnme;
}