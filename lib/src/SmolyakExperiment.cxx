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
#include "otsmolyak/SmolyakExperiment.hxx"
#include <openturns/PersistentObjectFactory.hxx>

using namespace OT;

namespace OTSMOLYAK
{

CLASSNAMEINIT(SmolyakExperiment);

/* Default constructor */
SmolyakExperiment::SmolyakExperiment()
  : TypedInterfaceObject<SmolyakImplementation>(new SmolyakImplementation)
{
  // Nothing to do
}


SmolyakExperiment::SmolyakExperiment(const SmolyakImplementation & implementation)
  : TypedInterfaceObject<SmolyakImplementation>(implementation.clone())
{
  // Nothing to do
}

Point SmolyakExperiment::square(Point & p) const
{
  return getImplementation()->square(p);
}

/* String converter */
String SmolyakExperiment::__repr__() const
{
  OSS oss;
  oss << "class=" << SmolyakExperiment::GetClassName()
      << " implementation=" << getImplementation()->__repr__();
  return oss;
}


} /* namespace OTSMOLYAK */
