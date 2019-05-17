//                                               -*- C++ -*-
/**
 *  @brief Abstract top-level view of an SmolyakExperiment
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
#ifndef OTSMOLYAK_SMOLYAKEXPERIMENT_HXX
#define OTSMOLYAK_SMOLYAKEXPERIMENT_HXX

#include "otsmolyak/OtSmolyakprivate.hxx"
#include "openturns/WeightedExperimentImplementation.hxx"

namespace OTSMOLYAK
{

/* forward declaration */
class SmolyakExperiment;


/**
 * @class SmolyakExperiment
 *
 * The class describes the probabilistic concept of SmolyakExperiment
 */
class OTSMOLYAK_API SmolyakExperiment
  : public OT::WeightedExperimentImplementation
{
  CLASSNAME;
public:


  /** Default constructor */
  SmolyakExperiment();

  /** Parameters constructor */
  explicit SmolyakExperiment(const UnsignedInteger size);

  /** Parameters constructor */
  SmolyakExperiment(const Distribution & distribution,
                       const UnsignedInteger size);

  /** String converter */
  OT::String __repr__() const;

  /* Here is the interface that all derived class must implement */

  /** Sample generation */
  Sample generateWithWeights(Point & weightsOut) const;

protected:

private:

}; /* class SmolyakExperiment */

} /* namespace OTSMOLYAK */

#endif /* OTSMOLYAK_SMOLYAKEXPERIMENT_HXX */
