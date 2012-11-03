#ifndef OOOIMessageListener_H
#define OOOIMessageListener_H

#include "OOOCode.h"

#define OOOInterface OOOIMessageListener
OOOVirtuals
	OOOVirtual(bool, onMessage, o_message * pMessage)
OOOVirtualsEnd
#undef OOOInterface

#endif
