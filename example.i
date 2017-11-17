%module example

%nodefaultctor FaceSense_; 
%nodefaultdtor FaceSense_; 

struct FaceSense_ { };
%{
#include "example.h"
%}



//%rename(FaceSense_) SWIGTYPE_p_FaceSensePtr;

//New and delete definitions for FaceSense_
//%newobject facesense_new;
//%delobject facesense_delete;

//%rename(FaceSensePtr) SWIGTYPE_p_FaceSense_;
//

%include "example.h"
