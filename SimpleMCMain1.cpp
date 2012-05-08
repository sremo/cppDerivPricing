// requires Random.cpp

#define PI 3.14159265
//#include <Random1.h>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;


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
    unsigned long NumberOfPaths = 1000000;

    if(argc > 1){
        from_string(Expiry,argv[1],dec);
        from_string(Strike,argv[2],dec);
        from_string(Spot,argv[3],dec);
        from_string(Vol,argv[4],dec);
        from_string(r,argv[5],dec);
        from_string(NumberOfPaths,argv[5],dec);
    }
    double optPrice = SimpleMontecarlo1(Expiry,Strike,Spot,Vol,r,NumberOfPaths);
    cout << "This is the price: " << optPrice << endl;
    return 0;


    }
