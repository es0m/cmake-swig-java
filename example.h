#ifndef INCLUDED_FACESENSE_H
#define INCLUDED_FACESENSE_H

#define FACESENSE_API

#ifdef __cplusplus
extern "C" {
#endif

extern int foo();


#include <stdint.h>

struct FaceSense_;
//typedef struct FaceSense_* FaceSensePtr;

//typedef struct FaceSense_* FaceSensePtr;

typedef struct FaceSensePoint2f_
{
    float x, y;
} FaceSensePoint2f;

FACESENSE_API
FaceSensePoint2f facesense_test_point(const struct FaceSense_* facesense);

/*
typedef struct FaceSenseRect_ {
  int32_t x, y, w, h;
} FaceSenseRect;

FACESENSE_API void facesense_set_rect(FaceSenseRect *faceSenseRect, int32_t x, int32_t y, int32_t w, int32_t h);
*/

/*! create a new tracker API
 * \note the tracker needs to be loaded with \ref facesense_load()
 */
FACESENSE_API struct FaceSense_*
facesense_new();

/*! frees FaceSense API as well as contained detector data
 *
 */
FACESENSE_API void
facesense_delete(struct FaceSense_* ft);



#ifdef __cplusplus
}
#endif

#endif
