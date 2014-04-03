#include <iostream>
using namespace std;

#include "Screen.h"
#include "TestIntegrator.h"
#include "Shape3d.h"
#include "Camera.h"
#include "SimpleSampler1D.h"

#include <random>

std::tr1::random_device rd;
std::tr1::mt19937 mt(rd());

int main(int argc, char** argv)
{
	cout << "test";

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
	size_t sampleCount = 100;
	Sampler* sampler = new SimpleSampler1D(sampleCount);
	std::tr1::uniform_real_distribution<> distribution;
	unsigned char* imageout = new unsigned char[100*100*3];
	size_t imageoutISIZE = 100;
	size_t imageoutJSIZE = 100;
	size_t imageoutKSIZE = 3;
	memset(imageout, 255, imageoutISIZE*imageoutJSIZE*imageoutKSIZE*sizeof(unsigned char));
	for (size_t i = 0; i < 10; i++)
	{
		//TODO: change this to return 2d samples???
		Sample sampx = sampler->getNextSample();
		Sample sampy = sampler->getNextSample();

		size_t x = static_cast<size_t>(sampx * static_cast<float>(imageoutISIZE));
		size_t y = static_cast<size_t>(sampy * static_cast<float>(imageoutJSIZE));

		i3(imageout, x, y, 0) = 0;
	}

	return 0;
}

//void draw();