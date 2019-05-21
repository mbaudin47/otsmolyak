#include <iostream>

#include "openturns/OT.hxx"
#include "openturns/OTtestcode.hxx"

#include "otsmolyak/OtSmolyak.hxx"

using namespace OT;
using namespace OT::Test;
using namespace OTSMOLYAK;

int main(int argc, char **argv)
{
  Smolyak algo(10);
  std::cout << algo << std::endl;
  SymbolicFunction f("x", "sin(x)");
  Scalar a = -4.5;
  Scalar b = 2.3;
  Interval intervalab = Interval(a, b);
  Scalar computedValue = algo.integrate(f, intervalab)[0];
  std::cout << "Computed value=" << computedValue << std::endl;
  Scalar referenceValue = cos(a) - cos(b);
  std::cout << "Reference value=" << referenceValue << std::endl;
  // Second, integrate a multi-valued function
  Interval bounds(Point(3, -1.0), Point(3, 1.0));
  Description vars(Description::BuildDefault(3, "x"));
  Description formulas(1);
  formulas[0] = "x0^2 + 2*x1^2 + 3*x2^2";
  SymbolicFunction integrand(vars, formulas);
  Point value(algo.integrate(integrand, bounds));
  std::cout << "value=" << value << ", calls=" << integrand.getCallsNumber() << std::endl;
  return 0;
}

