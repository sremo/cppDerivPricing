#include <iostream>
#include <string>
#include "SimpleMC2.h"
#include "PayOff2.h"

using namespace std;

int main(int argc, char*argv[]){
  double Expiry = 2;
  double Strike = 30;
  double Spot = 30;
  double Vol = 0.5;
  double r = 0.05;
  unsigned long NumberOfPaths = 10000000;
  char* OptionType; 
  if(argc == 8){
    Expiry = atof(argv[1]);//string_to_double(argv[1]);
    Strike = atof(argv[2]); //string_to_double(argv[2]);
    Spot = atof(argv[3]);// string_to_double(argv[3]);
    Vol = atof(argv[4]);//string_to_double(argv[4]);
    r = atof(argv[5]);//string_to_double(argv[5]);
    NumberOfPaths = atol(argv[6]);// string_to_int(argv[6]);
    OptionType = argv[7];
  }
  CallPayOff CallOption = CallPayOff(Strike);
  PutPayOff PutOption = PutPayOff(Strike);
  DoubleDigitalPayOff DoubleOption = DoubleDigitalPayOff(15, 30);
  DigitalCallPayOff DigitalCallOptionLower = DigitalCallPayOff(15);
  DigitalCallPayOff DigitalCallOptionUpper = DigitalCallPayOff(30);

  cout << SimpleMonteCarlo2(CallOption,Expiry, Spot, Vol, r, NumberOfPaths) <<endl;;
  cout << SimpleMonteCarlo2(PutOption,Expiry, Spot, Vol, r, NumberOfPaths) <<endl;;
 
  cout << SimpleMonteCarlo2(DoubleOption,Expiry, Spot, Vol, r, NumberOfPaths) <<endl;;
  cout << SimpleMonteCarlo2(DigitalCallOptionLower,Expiry, Spot, Vol, r, NumberOfPaths) <<endl;;
  cout << SimpleMonteCarlo2(DigitalCallOptionUpper,Expiry, Spot, Vol, r, NumberOfPaths) <<endl;;
  


  return 0;
}
