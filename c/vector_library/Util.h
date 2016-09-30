/*  ============== Galen Helfter ==============  */
/*  ==============     Util.h    ==============  */

#ifndef _UTIL_H_
#define _UTIL_H_

#define SQR(x) ((x)*(x))

/*  We must keep a definition of M_PI, since it isn't guaranteed
 *  in the C90 specification, which I usually target  */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*  Define an epsilon value  */
#ifndef EPS
#define EPS 0.001
#endif

#endif
