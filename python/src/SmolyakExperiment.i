// SWIG file SmolyakExperiment.i

%{
#include "otsmolyak/SmolyakExperiment.hxx"
%}

%include SmolyakExperiment_doc.i

%include otsmolyak/SmolyakExperiment.hxx
namespace OTSMOLYAK { %extend SmolyakExperiment { SmolyakExperiment(const SmolyakExperiment & other) { return new OTSMOLYAK::SmolyakExperiment(other); } } }
