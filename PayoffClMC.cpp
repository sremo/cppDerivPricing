// requires Random.cpp

#include "Random.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "PayOff.h"
using namespace std;


 double string_to_double( const std::string& s )
 {
   std::istringstream i(s);
   double x;
   if (!(i >> x))
     return 0;
   return x;
 } 

 int string_to_int( const std::string& s )
 {
   std::istringstream i(s);
   double x;
   if (!(i >> x))
     return 0;
   return x;
 } 



double PayoffMontecarlo(const PayOff &payoff,
                         double Expiry,
			 double Spot,
			 double Vol,
			 double r,
			 unsigned long NumberOfPaths)
{
	double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;

    double baseSpot = Spot*exp(r+itoCorrection);
    double thisSpot;
    double sum = 0;
    double thisGaussian;
    srand(time(0));
    
    for(int i=0; i<NumberOfPaths;i++){
        
        thisGaussian = GetGaussianBoxMuller();
        thisSpot = baseSpot*exp(thisGaussian*rootVariance);
        sum += payoff(thisSpot);

    }
    double mean = sum/NumberOfPaths;
    mean *= mean*exp(-r*Expiry);
    return mean;
}



int main(int argc, char* argv[]){
    

    double Expiry = 20;
    double Strike = 50;
    double Spot = 40;
    double Vol = 0.15;
    double r = 0.05;
    unsigned long NumberOfPaths = 10000000;

    if(argc == 7){
        Expiry = string_to_double(argv[1]);
        Strike = string_to_double(argv[2]);
        Spot = string_to_double(argv[3]);
        Vol = string_to_double(argv[4]);
        r = string_to_double(argv[5]);
        NumberOfPaths = string_to_int(argv[6]);
    }
    PayOff::PayOff callPayOff = PayOff(Strike, PayOff::call );
    PayOff::PayOff putPayOff = PayOff(Strike, PayOff::put);
    double optPriceCall = PayoffMontecarlo(callPayOff,Expiry,Spot,Vol,r,NumberOfPaths);
    double optPricePut = PayoffMontecarlo(putPayOff,Expiry,Spot,Vol,r,NumberOfPaths);
    cout << "This is the price of the Call: " << optPriceCall << " and of the Put: " << optPricePut<<  endl;
    return 0;


    }
