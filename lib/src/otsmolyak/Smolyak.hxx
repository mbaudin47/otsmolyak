//                                               -*- C++ -*-
/**
 *  @brief Abstract top-level view of an Smolyak integration algorithm.
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
#ifndef OTSMOLYAK_SMOLYAK_HXX
#define OTSMOLYAK_SMOLYAK_HXX

#include "otsmolyak/OtSmolyakprivate.hxx"
#include "openturns/IntegrationAlgorithmImplementation.hxx"

namespace OTSMOLYAK
{

/* forward declaration */
class Smolyak;


/**
 * @class Smolyak
 *
 * The class describes the probabilistic concept of Smolyak
 */
class OTSMOLYAK_API Smolyak
  : public OT::IntegrationAlgorithmImplementation
{
  CLASSNAME;
public:

  /** Default constructor without parameters */
  Smolyak();

  /** Parameters constructor */
  Smolyak(const OT::UnsignedInteger cubatureParameter);

  /** Virtual copy constructor */
  virtual Smolyak * clone() const;

  /** Compute an approximation of \int_{[a,b]}f(x)dx, where [a,b]
   * is an 1D interval
   */
  using IntegrationAlgorithmImplementation::integrate;

  /** Compute an approximation of \int_{[a,b]}f(x)dx, where [a,b]
   * is an n-D interval
   */
  OT::Point integrate(const OT::Function & function,
                      const OT::Interval & interval) const;

  /** String converter */
  virtual OT::String __repr__() const;

  /** String converter */
  virtual OT::String __str__(const OT::String & offset = "") const;

  /* Here is the interface that all derived class must implement */

protected:

private:

  /* Local integration rule */
  OT::UnsignedInteger cubatureParameter_;

}; /* class Smolyak */

} /* namespace OTSMOLYAK */

#endif /* OTSMOLYAK_SMOLYAK_HXX */
