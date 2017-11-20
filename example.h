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
  int32_t max_states, SpaceSenseStatePtr states);//, int32_t* n_frobnications);



#ifdef __cplusplus
}
#endif

#endif
