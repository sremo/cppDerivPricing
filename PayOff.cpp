#include "PayOff.h"


PayOff::PayOff(double Strike_, OptionType TheOptionsType_)
  :
  Strike(Strike_), TheOptionsType(TheOptionsType_)
{ }

double PayOff::operator () (double spot) const
{
  switch(TheOptionsType)
    {
    case call:
      return spot>Strike ? spot-Strike : 0; // max(spot - Strike,0);

    case put:
      return Strike>spot ? Strike - spot : 0; //Max(Strike - spot, 0);

    default:
      throw("unknow option type");

    }

}
