%module example

// constructor/destructor definitions must come *before* struct definitions
%nodefaultctor SpaceSense_; 
%nodefaultdtor SpaceSense_; 
struct SpaceSense_ { };




%{
#include "example.h"
%}
%include <stdint.i>
%include <arrays_java.i>
%include <carrays.i>
//JAVA_ARRAYSOFCLASSES(SpaceSenseState);
%array_class(SpaceSenseState, SpaceSenseStateArray);



//%rename(SpaceSense_) SWIGTYPE_p_SpaceSensePtr;

//New and delete definitions for SpaceSense_
//%newobject Spacesense_new;
//%delobject Spacesense_delete;

//%rename(SpaceSensePtr) SWIGTYPE_p_SpaceSense_;
//

// this needs to be added after definition of SpaceSenseStatePtr
//%array_functions(SpaceSenseStateArray, spacesensestatearray )


%include "example.h"

