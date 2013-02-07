#include <iostream>
#include <string>
#include "SimpleMC.h"
#include "PayOff.h"

using namespace std;

int main(int argc, char*argv[]){
  double Expiry = 50;
  double Strike = 20;
  double Spot = 30;
  double Vol = 0.5;
  double r = 2;
  unsigned long NumberOfPaths = 1000;
  if(argc == 7){
    Expiry = atof(argv[1]);//string_to_double(argv[1]);
    Strike = atof(argv[2]); //string_to_double(argv[2]);
    Spot = atof(argv[3]);// string_to_double(argv[3]);
    Vol = atof(argv[4]);//string_to_double(argv[4]);
    r = atof(argv[5]);//string_to_double(argv[5]);
    NumberOfPaths = atol(argv[6]);// string_to_int(argv[6]);
  }
  const PayOff option = PayOff(Strike, PayOff::call);
  cout << SimpleMonteCarlo2(option,Expiry, Spot, Vol, r, NumberOfPaths);



  return 0;
}
