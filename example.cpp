#include "example.h"
#include <iostream>

struct SpaceSense_ {
  float x;
  float y;
};

typedef SpaceSensePtr SpaceSensePtr;

SPACESENSE_API
SpaceSensePoint2f spacesense_test_point(const SpaceSensePtr spacesense)
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

SPACESENSE_API const char*
spacesense_version(SpaceSensePtr ft)
{
  return "Version 1";
}

SPACESENSE_API int32_t
spacesense_frobnicate(SpaceSensePtr d,
  int32_t max_states, SpaceSenseState* states)
{
  for ( int i=0; i<max_states; ++i ) {
    auto& s(states[i]);
    s.n_points = i;
    for ( int j=0; j<i; ++j ) {
      auto& ss(s.points[j]);
      ss.x = 1.0f*j;
      ss.y = 1.0f*j;
    }
  }
  return max_states;
}

SPACESENSE_API int32_t
spacesense_discombobulate(SpaceSensePtr d,
  int32_t max_states, SpaceSenseState* states, int32_t* n_xooxs)
{
  for ( int i=0; i<max_states; ++i ) {
    auto& s(states[i]);
    s.n_points = i;
    for ( int j=0; j<i; ++j ) {
      auto& ss(s.points[j]);
      ss.x = 1.0f*j;
      ss.y = 1.0f*j;
    }
  }
  *n_xooxs = max_states;
  return max_states;
}

SPACESENSE_API SpaceSenseImage* 
spacesense_image_new()
{
  SpaceSenseImage* image = new SpaceSenseImage;
  image->length = 0;
  image->data = 0;
  return image;
}

SPACESENSE_API void             
spacesense_image_delete(SpaceSenseImage* ip)
{
  delete ip;
}

SPACESENSE_API void             
spacesense_image_from_buffer(SpaceSenseImage* image, SpaceSensePixelPtr data, int32_t length)
{
  image->length = length;
  image->data = data;
}

SPACESENSE_API void             
spacesense_image_lollygag(SpaceSenseImage* ip, int32_t value)
{
  for ( int32_t i = 0; i<ip->length; ++i ) {
    ip->data[i] = (unsigned char)value;
  }
}


int foo() 
{
    return 124;
}
