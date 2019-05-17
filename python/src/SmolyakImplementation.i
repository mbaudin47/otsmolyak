// SWIG file SmolyakImplementation.i

%{
#include "otsmolyak/SmolyakImplementation.hxx"
%}

%include SmolyakImplementation_doc.i

%template(SmolyakImplementationdInterfaceObject)           OT::TypedInterfaceObject<OTSMOLYAK::SmolyakImplementation>;

%include otsmolyak/SmolyakImplementation.hxx
namespace OTSMOLYAK { %extend SmolyakImplementation { SmolyakImplementation(const SmolyakImplementation & other) { return new OTSMOLYAK::SmolyakImplementation(other); } } }
