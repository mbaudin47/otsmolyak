//                                               -*- C++ -*-
/**
 *  @brief SmolyakImplementation
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
#include "otsmolyak/SmolyakImplementation.hxx"
#include <openturns/PersistentObjectFactory.hxx>

using namespace OT;

namespace OTSMOLYAK
{

CLASSNAMEINIT(SmolyakImplementation);

static Factory<SmolyakImplementation> Factory_SmolyakImplementation;


/* Default constructor */
SmolyakImplementation::SmolyakImplementation()
  : PersistentObject()
{
  // Nothing to do
}

/* Virtual constructor method */
SmolyakImplementation * SmolyakImplementation::clone() const
{
  return new SmolyakImplementation(*this);
}

/* example of a func that return a point squared. */
Point SmolyakImplementation::square(Point& p) const
{

  Point p_out(p.getSize());
  for(UnsignedInteger i = 0; i < p.getSize(); ++ i)
  {
    p_out[i] = p[i] * p[i];
  }
  return p_out;
}

/* String converter */
String SmolyakImplementation::__repr__() const
{
  OSS oss;
  oss << "class=" << SmolyakImplementation::GetClassName();
  return oss;
}

/* Method save() stores the object through the StorageManager */
void SmolyakImplementation::save(Advocate & adv) const
{
  PersistentObject::save( adv );
}

/* Method load() reloads the object from the StorageManager */
void SmolyakImplementation::load(Advocate & adv)
{
  PersistentObject::load( adv );
}


} /* namespace OTSMOLYAK */
