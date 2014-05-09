#include <iostream>
using namespace std;

#include "PixelSampleExampleGenerators.h"

#include "StratifiedSampler2D.h"

#include <random>

int main(int argc, char** argv)
{
	//generate a bunch of samples and write to an image file to show them.
	size_t numSamples = 256;
	FloatRange xrange(0, 1);
	FloatRange yrange(0, 1);
	//RNG stuff, pass into sampler
	std::tr1::random_device rd;
	std::tr1::mt19937 mt(rd());
	//std::tr1::uniform_real_distribution<> distribution(0.0, 1.0);
	float u, v;
	
	Sampler2D* sampler;
	
	//2D GRID

	sampler = new StratifiedSampler2D(numSamples, &mt, xrange, yrange, 16, 16);
	generateExampleImage2DSampleGrid(sampler, "StratifiedSampler2D");
	delete sampler;


	//CHECKERS

	numSamples = EXAMPLENUMSAMPLES;

	sampler = new StratifiedSampler2D(numSamples, &mt, xrange, yrange,
		static_cast<size_t>(sqrtf(static_cast<float>(numSamples))),
		static_cast<size_t>(sqrtf(static_cast<float>(numSamples))));
	generateExampleImageInfiniteCheckers(sampler, "StratifiedSampler2D", &u, &v);
	delete sampler;

	return 0;
}
