#include <iostream>
using namespace std;

#include "PixelSampleExampleGenerators.h"

#include "HammerslyScrambledSampler2D.h"

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

	sampler = new HammerslyScrambledSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImage2DSampleGrid(sampler, "HammerslyScrambledSampler2D");
	delete sampler;


	//CHECKERS

	numSamples = EXAMPLENUMSAMPLES;

	sampler = new HammerslyScrambledSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImageInfiniteCheckers(sampler, "HammerslyScrambledSampler2D", &u, &v);
	delete sampler;

	
	return 0;
}
