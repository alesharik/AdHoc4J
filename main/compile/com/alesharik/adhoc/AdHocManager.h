#ifndef adhoc4j_AdHocManager_h
#define adhoc4j_AdHocManager_h

extern "C" {
    #include <adhoc.h>
}
#include "Utils.h"

static IDot11AdHocManager *manager;
static bool AdHocManager_init_is;

inline void AdHocManager_init();

#endif
