%module example

// constructor/destructor definitions must come *before* struct definitions
%nodefaultctor SpaceSense_; 
%nodefaultdtor SpaceSense_; 
struct SpaceSense_ { };

%{
#include "example.h"
%}

// stdint int32_t definitions
%include <stdint.i>
%include <arrays_java.i>
%include <carrays.i>
//JAVA_ARRAYSOFCLASSES(SpaceSenseState);
// interestingly, SpaceSenseStateArray is just used as a SpaceSenseState when calling frobnicate(). 
%array_class(SpaceSenseState, SpaceSenseStateArray);

// this needs to be added after definition of SpaceSensePoint2f
%array_class(SpaceSensePoint2f, SpaceSensePoint2fArray);

// this redefines the output variables of functions
%include "typemaps.i"
%apply int32_t *OUTPUT {int32_t *n_xooxs};

%include "example.h"

