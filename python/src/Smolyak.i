// SWIG file Smolyak.i

%{
#include "otsmolyak/Smolyak.hxx"
%}

%include Smolyak_doc.i

TypedInterfaceObjectImplementationHelper(OTSMOLYAK, Smolyak, SmolyakImplementation)

%include otsmolyak/Smolyak.hxx
namespace OTSMOLYAK { %extend Smolyak { Smolyak(const Smolyak & other) { return new OTSMOLYAK::Smolyak(other); } } }
