#include <iostream>
using namespace std;

#include "PixelSampleExampleGenerators.h"

#include "AdaptiveSampler2D.h"

#include "SimpleSampler2D.h"
#include "HaltonScrambledSampler2D.h"

#include <random>

float eval(Sample2D sample, float u, float v)
{
	ExamplePinholeCamera camera(EXAMPLEIMAGESIZE, EXAMPLEIMAGESIZE, 1.0f);
	return intersectCheckerboard(&camera, sample, u, v);
}

int main(int argc, char** argv)
{
	//generate a bunch of samples and write to an image file to show them.
	size_t numSamples = 256;
	FloatRange xrange(0, 1);
	FloatRange yrange(0, 1);
	//RNG stuff, pass into sampler
	std::tr1::random_device rd;
	std::tr1::mt19937 mt(rd());
	float u, v;
	
	Sampler2D* sampler;
	Sampler2D* sampler2;

	//No 2d grid, since there is no criteria there

	//CHECKERS

	numSamples = EXAMPLENUMSAMPLES;

	sampler2 = new SimpleSampler2D(numSamples, &mt, xrange, yrange);
	sampler = new AdaptiveSampler2D(numSamples, &mt, xrange, yrange, sampler2, eval, &u, &v);
	generateExampleImageInfiniteCheckers(sampler, "AdaptiveSimpleSampler2D", &u, &v);
	delete sampler2;
	delete sampler;

	sampler2 = new HaltonScrambledSampler2D(numSamples, &mt, xrange, yrange);
	sampler = new AdaptiveSampler2D(numSamples, &mt, xrange, yrange, sampler2, eval, &u, &v);
	generateExampleImageInfiniteCheckers(sampler, "AdaptiveHaltonScrambledSampler2D", &u, &v);
	delete sampler2;
	delete sampler;

	return 0;
}
