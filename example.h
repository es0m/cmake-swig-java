#ifndef INCLUDED_SPACESENSE_H
#define INCLUDED_SPACESENSE_H

#define SPACESENSE_API

#ifdef __cplusplus
extern "C" {
#endif

extern int foo();


#include <stdint.h>

struct SpaceSense_;
typedef struct SpaceSense_* SpaceSensePtr;

typedef struct SpaceSensePoint2f_
{
  float x, y;
} SpaceSensePoint2f;

SPACESENSE_API
SpaceSensePoint2f spacesense_test_point(const SpaceSensePtr spacesense);


/*! create a new tracker API
 * \note the tracker needs to be loaded with \ref spacesense_load()
 */
SPACESENSE_API SpaceSensePtr
spacesense_new();

/*! frees SpaceSense API as well as contained detector data
 *
 */
SPACESENSE_API void
spacesense_delete(SpaceSensePtr ft);

/*! returns the SpaceSense API version. 
*
*/
SPACESENSE_API const char*
spacesense_version(SpaceSensePtr ft);


#define SPACESENSE_MAX_POINTS (256)
typedef struct SpaceSenseState_
{
  int32_t n_points;
  SpaceSensePoint2f points[SPACESENSE_MAX_POINTS];
} SpaceSenseState;

typedef SpaceSenseState* SpaceSenseStatePtr;

#define SPACESENSE_MAX_STATES (256)

///// test for arrays of objects being passed
/*! frobnicates the states 
  (sets the number of points and the values of points in x/y to their index in the array)
 */
SPACESENSE_API int32_t
spacesense_frobnicate(SpaceSensePtr d,
  int32_t max_states, SpaceSenseStatePtr states);

/*! discombobulates the states 
  (sets the number of points and the values of points in x/y to their index in the array)
 */
SPACESENSE_API int32_t
spacesense_discombobulate(SpaceSensePtr d,
  int32_t max_states, SpaceSenseStatePtr states, int32_t* n_xooxs);


/*! test handling of unsigned char pointers etc. 
 */
typedef unsigned char* SpaceSensePixelPtr;
typedef struct SpaceSenseImage_
{
  int32_t length;
  SpaceSensePixelPtr data;
} SpaceSenseImage;

SPACESENSE_API SpaceSenseImage* spacesense_image_new();
SPACESENSE_API void             spacesense_image_delete(SpaceSenseImage* ip);
SPACESENSE_API void             spacesense_image_from_buffer(SpaceSenseImage*, SpaceSensePixelPtr data, int32_t length);

/*! sets the image to the given value
 */
SPACESENSE_API void             spacesense_image_lollygag(SpaceSenseImage* ip, int32_t value);


#ifdef __cplusplus
}
#endif

#endif
