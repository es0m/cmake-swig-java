#include "example.h"


struct FaceSense_ {
  float x;
  float y;
};

typedef struct FaceSense_* FaceSensePtr;

FACESENSE_API
FaceSensePoint2f facesense_test_point(const struct FaceSense_* facesense)
{
  FaceSensePoint2f f;
  f.x = facesense->x;
  f.y = facesense->y;
  return f;
}

/*
typedef struct FaceSenseRect_ {
  int32_t x, y, w, h;
} FaceSenseRect;

FACESENSE_API void facesense_set_rect(FaceSenseRect *faceSenseRect, int32_t x, int32_t y, int32_t w, int32_t h);
*/

/*! create a new tracker API
 * \note the tracker needs to be loaded with \ref facesense_load()
 */
FACESENSE_API FaceSensePtr
facesense_new()
{
  FaceSensePtr fs = new FaceSense_;
  fs->x = 100; 
  fs->y = 200;
  return fs;
}


/*! frees FaceSense API as well as contained detector data
 *
 */
FACESENSE_API void
facesense_delete(FaceSensePtr fs)
{
  delete fs;
}



int foo() 
{
    return 124;
}
