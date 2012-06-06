// requires Random.cpp

#define PI 3.14159265
//#include <Random1.h>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <PayOff.h>
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


double GetGaussianBoxMuller(){

    double U1 = ((double)rand())/RAND_MAX;
    double U2 = ((double)rand())/RAND_MAX;
    return sqrt(-2*log(U1))*cos(2*PI*U2);


}

double SimpleMontecarlo1(double Expiry,
			 double Strike,
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
    double payoff;
    double thisGaussian;
    srand(time(0));
    
    for(int i=0; i<NumberOfPaths;i++){
        
        thisGaussian = GetGaussianBoxMuller();
        thisSpot = baseSpot*exp(thisGaussian*rootVariance);
        payoff = thisSpot - Strike;
        payoff = payoff >0 ? payoff : 0;
        sum += payoff;

    }
    double mean = sum/NumberOfPaths;
    mean *= mean*exp(-r*Expiry);
    return mean;
}



int main(int argc, char* argv[]){
    

    double Expiry = 40;
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
    double optPrice = SimpleMontecarlo1(Expiry,Strike,Spot,Vol,r,NumberOfPaths);
    cout << "This is the price: " << optPrice << endl;
    return 0;


    }
