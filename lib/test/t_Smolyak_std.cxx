#include <iostream>

#include "openturns/OT.hxx"
#include "openturns/OTtestcode.hxx"

#include "otsmolyak/OtSmolyak.hxx"

using namespace OT;
using namespace OT::Test;
using namespace OTSMOLYAK;

int main(int argc, char **argv)
{
  Smolyak algo;
  std::cout << algo << std::endl;
  SymbolicFunction f("x", "sin(x)");
  Scalar a = -2.5;
  Scalar b = 4.5;
  Interval intervalab = Interval(a, b);
  Scalar computedValue = algo.integrate(f, intervalab)[0];
  std::cout << "Computed value=" << computedValue << std::endl;
  Scalar referenceValue = cos(a) - cos(b);
  std::cout << "Reference value=" << referenceValue << std::endl;
  return 0;
}

