#ifndef OOOMessagePump_H
#define OOOMessagePump_H

#include "OOOCode.h"
#include "OOOIMessagePumpController.h"
#include "OOOIMessageListener.h"

#define OOOClass OOOMessagePump
OOODeclare()
	OOOImplements
	OOOImplementsEnd
	OOOExports
		OOOExport(void, start, OOOIMessagePumpController * iMessagePumpController)
		OOOExport(void, stop)
		OOOExport(void, addListener, OOOIMessageListener * iMessageHandler)
		OOOExport(void, removeListener, OOOIMessageListener * iMessageHandler)
	OOOExportsEnd
OOODeclareEnd
#undef OOOClass

#endif
