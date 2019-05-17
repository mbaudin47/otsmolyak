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
#include "otsmolyak/Smolyak.hxx"
#include "otsmolyak/SmolyakImplementation.hxx"
#include <openturns/PersistentObjectFactory.hxx>

using namespace OT;

namespace OTSMOLYAK
{

CLASSNAMEINIT(Smolyak);

/* Default constructor */
Smolyak::Smolyak()
  : TypedInterfaceObject<SmolyakImplementation>(new SmolyakImplementation)
{
  // Nothing to do
}


Smolyak::Smolyak(const SmolyakImplementation & implementation)
  : TypedInterfaceObject<SmolyakImplementation>(implementation.clone())
{
  // Nothing to do
}

Point Smolyak::square(Point & p) const
{
  return getImplementation()->square(p);
}

/* String converter */
String Smolyak::__repr__() const
{
  OSS oss;
  oss << "class=" << Smolyak::GetClassName()
      << " implementation=" << getImplementation()->__repr__();
  return oss;
}


} /* namespace OTSMOLYAK */
