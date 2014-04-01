#include <iostream>
using namespace std;

#include "Screen.h"
#include "TestIntegrator.h"
#include "Shape3d.h"
#include "Camera.h"
#include "SimpleSampler.h"

int main(int argc, char** argv)
{
	cout << "test";

	//Camera, resolution, sensor size diag meters, sensor 
	Camera camera(800, 600, 90, 5, 0.1f);
	TestIntegrator integrator;

	Shape3d box("box.obj");
	
	SimpleSampler sampler;

	//for now, start casting right away
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < camera.getWidth(); i++)
	{
		for (j = 0; j < camera.getHeight(); j++)
		{
			float u = static_cast<float>(i) / static_cast<float>(camera.getWidth());
			float v = static_cast<float>(j) / static_cast<float>(camera.getHeight());

			//generate origin samples
			Sample originx = sampler.getSample();
			Sample originy = sampler.getSample();
			Sample aperturex = sampler.getSample();
			Sample aperturey = sampler.getSample();

			//shoot ray into scene
			Ray shootme = camera.getRay(originx, originy, aperturex, aperturey);
			
			camera.exposeSensor(i, j, &integrator, &shootme);
		}
	}



	//TODO: openGL part

	return 0;
}

//void draw();