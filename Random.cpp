#include "Random.h"
#include <cmath>
#include <stdlib.h>
#define PI 3.14159265
using namespace std;

double GetGaussianBoxMuller(){

  double U1 = rand()/static_cast<double>(RAND_MAX);
  double U2 = rand()/static_cast<double>(RAND_MAX);
  return sqrt(-2*log(U1))*cos(2*PI*U2);


}
