#include "example.h"


struct SpaceSense_ {
  float x;
  float y;
};

typedef struct SpaceSense_* SpaceSensePtr;

SPACESENSE_API
SpaceSensePoint2f spacesense_test_point(const struct SpaceSense_* spacesense)
{
  SpaceSensePoint2f f;
  f.x = spacesense->x;
  f.y = spacesense->y;
  return f;
}

/*
typedef struct SpaceSenseRect_ {
  int32_t x, y, w, h;
} SpaceSenseRect;

SPACESENSE_API void spacesense_set_rect(SpaceSenseRect *spaceSenseRect, int32_t x, int32_t y, int32_t w, int32_t h);
*/

/*! create a new tracker API
 * \note the tracker needs to be loaded with \ref spacesense_load()
 */
SPACESENSE_API SpaceSensePtr
spacesense_new()
{
  SpaceSensePtr fs = new SpaceSense_;
  fs->x = 100; 
  fs->y = 200;
  return fs;
}


/*! frees SpaceSense API as well as contained detector data
 *
 */
SPACESENSE_API void
spacesense_delete(SpaceSensePtr fs)
{
  delete fs;
}



int foo() 
{
    return 124;
}
