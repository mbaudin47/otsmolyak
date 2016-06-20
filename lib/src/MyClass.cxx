//                                               -*- C++ -*-
/**
 *  @brief MyClass
 *
 *  Copyright 2005-2016 Airbus-EDF-IMACS-Phimeca
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
#include "ottemplate/MyClass.hxx"
#include <PersistentObjectFactory.hxx>
#include "ottemplate/MyClassImplementation.hxx"

using namespace OT;

namespace OTTEMPLATE
{

CLASSNAMEINIT(MyClass);

/* Default constructor */
MyClass::MyClass()
  : TypedInterfaceObject<MyClassImplementation>(new MyClassImplementation)
{
  // Nothing to do
}


MyClass::MyClass(const MyClassImplementation & implementation)
  : TypedInterfaceObject<MyClassImplementation>(implementation.clone())
{
  // Nothing to do
}

NumericalPoint MyClass::square(NumericalPoint& p) const
{
  return getImplementation()->square(p);
}

/* String converter */
String MyClass::__repr__() const
{
  OSS oss;
  oss << "class=" << MyClass::GetClassName()
      << " implementation=" << getImplementation()->__repr__();
  return oss;
}


} /* namespace OTTEMPLATE */
