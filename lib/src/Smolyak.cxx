//                                               -*- C++ -*-
/**
 *  @brief Smolyak
 *
 *  Copyright 2005-2019 Airbus-EDF-IMACS-ONERA-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "otsmolyak/smolpack.hh"
#include "otsmolyak/Smolyak.hxx"
#include <openturns/PersistentObjectFactory.hxx>

using namespace OT;

namespace OTSMOLYAK
{

CLASSNAMEINIT(Smolyak);

/* Default constructor */
Smolyak::Smolyak():
  IntegrationAlgorithmImplementation()
  , cubatureParameter_(0)
{
  // Nothing to do
}

/* Constructor with parameters */
Smolyak::Smolyak(const UnsignedInteger cubatureParameter):
  IntegrationAlgorithmImplementation()
  , cubatureParameter_(cubatureParameter)
{
  // Nothing to do
}

/* String converter */
String Smolyak::__repr__() const
{
  OSS oss;
  oss << "class=" << GetClassName()
      << " name=" << getName()
      << " cubatureParameter=" << cubatureParameter_;
  return oss;
}

/* String converter */
String Smolyak::__str__(const String & offset) const
{
  OSS oss(false);
  oss << Smolyak::GetClassName()
      << "(cubatureParameter=" << cubatureParameter_
      << ")";
  return oss;
}


/* Virtual constructor */
Smolyak * Smolyak::clone() const
{
  return new Smolyak(*this);
}

/** Compute an approximation of \int_{[a,b]}f(x)dx, where [a,b]
* is an n-D interval
*/
Point Smolyak::integrate(const Function & function,
                         const Interval & interval) const
{
  const UnsignedInteger inputDimension = function.getInputDimension();
  const UnsignedInteger outputDimension = function.getOutputDimension();
  const UnsignedInteger print_stats = 0; // Do not print outputs
  Point result(outputDimension);
  result[0] = OTSMOLPACK::int_smolyak(inputDimension, cubatureParameter_, Smolyak::ComputeFunction, print_stats, (void*) function)
  return result;
}

/** Wrapper of the Function operator() compatible with
* smolyak signature, 
* adapted from openturns/lib/src/Base/Optim/Cobyla.cxx
*/
double Smolyak::ComputeFunction(int inputDimension,
                                double *x,
                                void *state)
{
  /* Convert the input vector in OpenTURNS format */
  Point inPoint(inputDimension);
  memcpy(&inPoint[0], x, inputDimension * sizeof(Scalar));

  /* Evaluate the function */
  Function *function = static_cast<Function *>(state);
  Point outPoint(function->operator()(inPoint));
  
  double returnValue = outPoint[0];

  return returnValue;
}

} /* namespace OTSMOLYAK */
