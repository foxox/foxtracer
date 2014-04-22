#ifndef COMMON_H
#define COMMON_H

#include <limits>
#include <iostream>
#include <cmath>

using namespace std;

#include "../ImageIO/ImageIO.h"

#define i2(arr,i,j) arr[((i) * (arr ## JSIZE)) + (j)]

//TODO: Have these use precomputed JSIZE * KSIZE, JSIZE * KSIZE * LSIZE, KSIZE*LSIZE
//ehhh... compiler probably does that anyway.

#define i3(arr,i,j,k) arr[((i) * ((arr ## JSIZE) * (arr ## KSIZE))) + (j) * (arr ## KSIZE) + (k)]
//#define i3s(arr,i,j,k,jSize,kSize) arr[( (i) * (jSize) * (kSize) ) + (j) * (kSize) + (k)]

#define i4(arr,i,j,k,l) arr[(  (i) * ( (arr ## JSIZE) * (arr ## KSIZE) * (arr ## LSIZE) )  ) + (j) * (  (arr ## KSIZE) * (arr ## LSIZE)  ) + (k) * (arr ## LSIZE) + (l)]
//#define i4s(arr,i,j,k,l,jSize,kSize,lSize) arr[( (i) * (jSize) * (kSize) * (lSize) ) + (j) * ((kSize) * (lSize)) + (k) * (lSize) + (l)]

//Radical Inverse
//Based on implementation in Physically Based Rendering by Matt Pharr and Greg Humphreys, Second Edition
inline double radicalInverse(int n, int base)
{
#if _DEBUG
	if (base == 1)
		throw new invalid_argument("Radical inverse base cannot be 1 with this implementation.");
#endif

	double val = 0;
	double invBase = 1.0 / static_cast<double>(base);
	double invBi = invBase;
	while (n > 0)
	{
		int d_i = (n % base);
		val += d_i * invBi;
		n = static_cast<int>(static_cast<float>(n) * invBase);
		//n *= invBase;
		invBi *= invBase;
	}
	return val;
}


#endif