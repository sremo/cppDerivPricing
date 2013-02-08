#ifndef PAYOFF2_H
#define PAYOFF2_H


class PayOff{
 public:
 
  PayOff();
  virtual double operator() (double Spot) const = 0;
  virtual ~PayOff();

  //private:
  // double Strike;
 

};

class CallPayOff: public PayOff{
 public:
  CallPayOff(double Strike_);
  virtual double operator () (double Spot) const;
  virtual ~CallPayOff();

 private:
  double Strike;
};

class PutPayOff: public PayOff {
 public:
  PutPayOff(double Strike_);
  virtual double operator () (double Spot) const;
  virtual ~PutPayOff();

 private:
  double Strike;
};

class DoubleDigitalPayOff: public PayOff {
 public:
  DoubleDigitalPayOff(double LowerStrike_, double UpperStrike_);
  virtual double operator () (double Spot) const;
  virtual ~DoubleDigitalPayOff();
 private:
  double LowerStrike;
  double UpperStrike;
};

class DigitalCallPayOff: public PayOff {
 public: 
  DigitalCallPayOff(double Strike_);
  virtual double operator () (double Spot) const;
  virtual ~DigitalCallPayOff();
 private:
  double Strike;

};
class DigitalPutPayOff: public PayOff {
 public: 
  DigitalPutPayOff(double Strike_);
  virtual double operator () (double Spot) const;
  virtual ~DigitalPutPayOff();
 private:
  double Strike;

};


#endif
