#include <limits>
#include <iostream>
#include <cmath>

using namespace std;

#include "../ImageIO/ImageIO.h"

#define i2(arr,i,j) arr[((i) * (arr ## JSIZE)) + (j)]

//TODO: Have these use precomputed JSIZE * KSIZE, JSIZE * KSIZE * LSIZE, KSIZE*LSIZE

#define i3(arr,i,j,k) arr[((i) * ((arr ## JSIZE) * (arr ## KSIZE))) + (j) * (arr ## KSIZE) + (k)]
//#define i3s(arr,i,j,k,jSize,kSize) arr[( (i) * (jSize) * (kSize) ) + (j) * (kSize) + (k)]

#define i4(arr,i,j,k,l) arr[(  (i) * ( (arr ## JSIZE) * (arr ## KSIZE) * (arr ## LSIZE) )  ) + (j) * (  (arr ## KSIZE) * (arr ## LSIZE)  ) + (k) * (arr ## LSIZE) + (l)]
//#define i4s(arr,i,j,k,l,jSize,kSize,lSize) arr[( (i) * (jSize) * (kSize) * (lSize) ) + (j) * ((kSize) * (lSize)) + (k) * (lSize) + (l)]