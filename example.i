%module example

// constructor/destructor definitions must come *before* struct definitions
%nodefaultctor SpaceSense_; 
%nodefaultdtor SpaceSense_; 
struct SpaceSense_ { };

%{
#include "example.h"
%}



//%rename(SpaceSense_) SWIGTYPE_p_SpaceSensePtr;

//New and delete definitions for SpaceSense_
//%newobject Spacesense_new;
//%delobject Spacesense_delete;

//%rename(SpaceSensePtr) SWIGTYPE_p_SpaceSense_;
//

%include "example.h"
