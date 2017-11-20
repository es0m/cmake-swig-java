#ifndef INCLUDED_SPACESENSE_H
#define INCLUDED_SPACESENSE_H

#define SPACESENSE_API

#ifdef __cplusplus
extern "C" {
#endif

extern int foo();


#include <stdint.h>

struct SpaceSense_;
//typedef struct SpaceSense_* SpaceSensePtr;

//typedef struct SpaceSense_* SpaceSensePtr;

typedef struct SpaceSensePoint2f_
{
    float x, y;
} SpaceSensePoint2f;

SPACESENSE_API
SpaceSensePoint2f spacesense_test_point(const struct SpaceSense_* spacesense);

/*
typedef struct SpaceSenseRect_ {
  int32_t x, y, w, h;
} SpaceSenseRect;

SPACESENSE_API void spacesense_set_rect(SpaceSenseRect *spaceSenseRect, int32_t x, int32_t y, int32_t w, int32_t h);
*/

/*! create a new tracker API
 * \note the tracker needs to be loaded with \ref spacesense_load()
 */
SPACESENSE_API struct SpaceSense_*
spacesense_new();

/*! frees SpaceSense API as well as contained detector data
 *
 */
SPACESENSE_API void
spacesense_delete(struct SpaceSense_* ft);



#ifdef __cplusplus
}
#endif

#endif
