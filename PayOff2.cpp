#include "PayOff2.h"

PayOff::PayOff()
{}

PayOff::~PayOff(){}


CallPayOff::CallPayOff(double Strike_)
  :
  Strike(Strike_)
{}

double CallPayOff::operator () (double Spot) const
{
  return Spot>Strike ? Spot-Strike: 0;
}

CallPayOff::~CallPayOff()
{}

PutPayOff::PutPayOff(double Strike_): Strike(Strike_)
{}

double PutPayOff::operator () (double Spot) const
{
  return Spot<Strike ? Strike-Spot: 0;
}


PutPayOff::~PutPayOff()
{}

DoubleDigitalPayOff:: DoubleDigitalPayOff(double LowerStrike_, double UpperStrike_)
  :
  LowerStrike(LowerStrike_),
  UpperStrike(UpperStrike_)
{}
double DoubleDigitalPayOff:: operator () (double Spot) const{
  return Spot > LowerStrike && Spot < UpperStrike ? 1 : 0;
}

DoubleDigitalPayOff:: ~DoubleDigitalPayOff()
{}

DigitalCallPayOff:: DigitalCallPayOff(double Strike_)
  :
  Strike(Strike_)
{}

double DigitalCallPayOff:: operator () (double Spot) const {
  return Spot > Strike? 1:0;
}

DigitalCallPayOff::~DigitalCallPayOff()
{}




DigitalPutPayOff:: DigitalPutPayOff(double Strike_)
  :
  Strike(Strike_)
{}

double DigitalPutPayOff:: operator () (double Spot) const {
  return Spot > Strike? 1:0;
}

DigitalPutPayOff::~DigitalPutPayOff()
{}
