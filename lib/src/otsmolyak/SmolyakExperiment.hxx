//                                               -*- C++ -*-
/**
 *  @brief SmolyakExperiment
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

#include <openturns/TypedInterfaceObject.hxx>
#include <openturns/StorageManager.hxx>
#include <openturns/Point.hxx>
#include "otsmolyak/OtSmolyakprivate.hxx"

namespace OTSMOLYAK
{

/* forward declaration */
class SmolyakImplementation;

/**
 * @class SmolyakExperiment
 *
 * SmolyakExperiment is some SmolyakExperiment type to illustrate how to add some classes in Open TURNS
 */
class OTSMOLYAK_API SmolyakExperiment
  : public OT::TypedInterfaceObject<SmolyakImplementation>
{
  CLASSNAME;

public:

  /** Default constructor */
  SmolyakExperiment();

  /** Constructor from implementation */
  SmolyakExperiment(const SmolyakImplementation & implementation);

  /** a func that return a point squared. **/
  OT::Point square(OT::Point & p) const;

  /** String converter */
  OT::String __repr__() const;

private:

}; /* class SmolyakExperiment */

} /* namespace OTSMOLYAK */

#endif /* OTSMOLYAK_SMOLYAKEXPERIMENT_HXX */
