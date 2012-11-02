#ifndef OOOIMessageHandler_H
#define OOOIMessageHandler_H

#include "OOOCode.h"

#define OOOInterface OOOIMessageHandler
OOOVirtuals
	OOOVirtual(bool, doMessage, o_message * pMessage)
OOOVirtualsEnd
#undef OOOInterface

#endif
