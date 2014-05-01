#include "AdaptiveSampler2D.h"


AdaptiveSampler2D::~AdaptiveSampler2D(void)
{
}

Sample2D AdaptiveSampler2D::getNextSample()
{
	this->samplecount++;

	Sample2D returnme = this->sampler->getNextSample();

	samples[samplecount - 1] = returnme;

	if (this->samplecount == this->getNumSamples()
		&&
		this->samplecount < this->maxNumSamples
		&&
		this->needsMoreSamples()
		)
	{
		this->numSamplesExpanded += this->numSamples;
		
		Sample2D* oldsamples = this->samples;
		this->samples = new Sample2D[this->numSamplesExpanded];
		//memcpy_s(this->samples, sizeof(Sample2D) * this->numSamplesExpanded, oldsamples, sizeof(Sample2D) * (this->numSamplesExpanded - this->numSamples));
		for (size_t i = 0; i < this->numSamplesExpanded - this->numSamples; i++)
			this->samples[i] = oldsamples[i];
		delete[] oldsamples;

		if (this->sampler->shouldReinitializeIfOversampled)
			this->sampler->reinitialize();
	}

	return returnme;
}