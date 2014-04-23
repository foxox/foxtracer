#include <iostream>
using namespace std;

#include "Screen.h"
#include "TestIntegrator.h"
#include "Shape3d.h"
#include "Camera.h"
#include "SimpleSampler2D.h"
#include "StratifiedSampler2D.h"
#include "LatinHypercubeSampler2D.h"
#include "HaltonSampler2D.h"
#include "HammerslySampler2D.h"
#include "VanDerCorputSobolSampler2D.h"

#include <random>

void generateExampleImage(Sampler2D* sampler, string name);

int main(int argc, char** argv)
{
	//cout << "test";

	//Camera, resolution, sensor size diag meters, sensor 
	//Camera camera(800, 600, 90, 5, 0.1f);
	//TestIntegrator integrator;

	//Shape3d box("box.obj");
	
	//SimpleSampler1D sampler;

	////for now, start casting right away
	//size_t i = 0;
	//size_t j = 0;
	//for (i = 0; i < camera.getWidth(); i++)
	//{
	//	for (j = 0; j < camera.getHeight(); j++)
	//	{
	//		float u = static_cast<float>(i) / static_cast<float>(camera.getWidth());
	//		float v = static_cast<float>(j) / static_cast<float>(camera.getHeight());

	//		//generate origin and aperture ray samples for this pixel (later this may be a batch)
	//		Sample originx = sampler.getNextSample();
	//		Sample originy = sampler.getNextSample();
	//		Sample aperturex = sampler.getNextSample();
	//		Sample aperturey = sampler.getNextSample();

	//		//time sample
	//		Sample time = sampler.getNextSample();

	//		//shoot ray into scene
	//		Ray shootme = camera.getRay(originx, originy, aperturex, aperturey);
	//		


	//		camera.exposeSensor(i, j, &integrator, &shootme);
	//	}
	//}


	//generate a bunch of samples and write to an image file to show them.
	const size_t numSamples = 200;
	FloatRange xrange(0, 1);
	FloatRange yrange(0, 1);
	//RNG stuff, pass into sampler
	std::tr1::random_device rd;
	std::tr1::mt19937 mt(rd());
	//std::tr1::uniform_real_distribution<> distribution(0.0, 1.0);
	
	Sampler2D* sampler;
	
	sampler = new SimpleSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImage(sampler, "simple");
	delete sampler;

	sampler = new StratifiedSampler2D(numSamples, &mt, xrange, yrange, 10, 10);
	generateExampleImage(sampler, "stratified");
	delete sampler;

	sampler = new LatinHypercubeSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImage(sampler, "latinhypercube");
	delete sampler;

	sampler = new HaltonSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImage(sampler, "haltonsampler");
	delete sampler;
	
	sampler = new HammerslySampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImage(sampler, "hammerslysampler");
	delete sampler;

	sampler = new VanDerCorputSobolSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImage(sampler, "vandercorputsobolsampler");
	delete sampler;

	return 0;
}

void generateExampleImage(Sampler2D* sampler, string name)
{
	const size_t imageoutSideSize = 200;
	const size_t imageoutISIZE = imageoutSideSize;
	const size_t imageoutJSIZE = imageoutSideSize;
	const size_t imageoutKSIZE = 3;
	unsigned char* imageout = new unsigned char[imageoutISIZE*imageoutJSIZE*imageoutKSIZE];
	memset(imageout, 255, imageoutISIZE*imageoutJSIZE*imageoutKSIZE*sizeof(unsigned char));

	//Draw lines
	const size_t numDivs = 10;
	for (size_t i = 1; i < numDivs; i++)
	{
		size_t i10 = i * imageoutSideSize / numDivs;

		//Draw row
		for (size_t j = 0; j < imageoutJSIZE; j++)
		{
			//i3(imageout, i10, j, 0) = 128;
			i3(imageout, i10, j, 1) = 128;
			i3(imageout, i10, j, 2) = 128;
		}

		//Draw col
		for (size_t j = 0; j < imageoutISIZE; j++)
		{
			//i3(imageout, j, i10, 0) = 128;
			i3(imageout, j, i10, 1) = 128;
			i3(imageout, j, i10, 2) = 128;
		}
	}

	//Samples!
	for (size_t i = 0; i < sampler->getNumSamples(); i++)
	{
		Sample2D samp = sampler->getNextSample();

		//samp.x = static_cast<float>(distribution(mt));
		//samp.y = static_cast<float>(distribution(mt));

		size_t x = static_cast<size_t>(samp.x * static_cast<float>(imageoutISIZE));
		size_t y = static_cast<size_t>(samp.y * static_cast<float>(imageoutJSIZE));

		//cout << x << "," << y << endl;

		i3(imageout, y, x, 0) = 0;
		i3(imageout, y, x, 1) = 0;
		i3(imageout, y, x, 2) = 0;
	}

	ImageOutRGB2BMP(name+".bmp", imageoutISIZE, imageoutJSIZE, imageout);
}