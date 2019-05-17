// SWIG file otsmolyak_module.i

%module(docstring="otsmolyak module") otsmolyak

%{
#include <openturns/OT.hxx>
#include <openturns/PythonWrappingFunctions.hxx>
%}

// Prerequisites needed
%include typemaps.i
%include exception.i
%ignore *::load(OT::Advocate & adv);
%ignore *::save(OT::Advocate & adv) const;

%import base_module.i
%import uncertainty_module.i

// The new classes
%include otsmolyak/OtSmolyakprivate.hxx
%include SmolyakImplementation.i
%include Smolyak.i


