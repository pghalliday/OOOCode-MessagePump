#ifndef OOOIMessagePumpController_H
#define OOOIMessagePumpController_H

#include "OOOCode.h"

#define OOOInterface OOOIMessagePumpController
OOOVirtuals
	OOOVirtual(void, started)
	OOOVirtual(void, stopped)
OOOVirtualsEnd
#undef OOOInterface

#endif
