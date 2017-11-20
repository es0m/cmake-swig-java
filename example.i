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

// these are definitions to map byte[] to int
//%typemap(in) (long , int) {
//  $1 = facesense_image_new($input);
//}
//%typemap(javain) cv::Mat "$javainput.dataAddr()"

//%apply long INPUT {unsigned char* data};

//%array_class(unsigned char,ByteArray);
%typemap(jtype) SpaceSensePixelPtr "long"
%typemap(jstype) SpaceSensePixelPtr "long"
%typemap(jni) SpaceSensePixelPtr "unsigned char*"
%typemap(javain) SpaceSensePixelPtr "$javainput"
%ignore SpaceSenseImage_::data;
%ignore SpaceSenseImage_::length;

//%typemap(in)  SpaceSensePixelPtr {
//  $1 = (unsigned char*)$input;
//}

//%typemap(jstype) SpaceSensePixelPtr "long"
//%typemap(jni)    SpaceSensePixelPtr "jlong"

%newobject spacesense_image_new;
%delobject spacesense_image_delete;

%include "example.h"

