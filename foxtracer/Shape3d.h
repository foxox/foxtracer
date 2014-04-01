#pragma once

#include <vector>
#include <string>

#include "foxmath3.h"

//http://kixor.net/dev/objloader/

using namespace std;
using namespace FM;

class Face
{
public:
	uint vertIndexes[3];
};

class Shape3d
{
private:
	vector<Vec3> verts;
	vector<uint> faces;

public:
	Shape3d(void);
	Shape3d(string fileName);
	~Shape3d(void);
};

