#include "SimpleMC.h"
#include "Random.h"
#includ <cmath.h>

using namespace std;

double SimpleMonteCarlo2(const PayOff& thePayOff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths
                         ){

  double variance = Vol*Vol*Expiry;
  double variance_root = sqrt(variance);
  double base_price = Spot*exp((r-0.5*Vol*Vol)*Expiry);

  double sum = 0;
  for(int i=0;i<NumberOfPaths; i++){
    sum += thePayOff(base_price*exp(variance_root*GetGaussianBoxMuller()));
  }
  
  return exp(-r*Expiry)*sum/NumberOfPaths;

}
