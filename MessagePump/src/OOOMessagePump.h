#ifndef OOOMessagePump_H
#define OOOMessagePump_H

#include "OOOCode.h"
#include "OOOIMessagePumpController.h"
#include "OOOIMessageHandler.h"

#define OOOClass OOOMessagePump
OOODeclare()
	OOOImplements
	OOOImplementsEnd
	OOOExports
		OOOExport(void, start, OOOIMessagePumpController * iMessagePumpController)
		OOOExport(void, stop)
		OOOExport(void, addHandler, OOOIMessageHandler * iMessageHandler)
		OOOExport(void, removeHandler, OOOIMessageHandler * iMessageHandler)
	OOOExportsEnd
OOODeclareEnd
#undef OOOClass

#endif
