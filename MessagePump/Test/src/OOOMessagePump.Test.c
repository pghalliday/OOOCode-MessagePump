#include "OOOUnitTestDefines.h"
#include "OOOMessagePump.h"

#define OOOClass MessagePumpTest
OOODeclare()
	OOOImplements
		OOOImplement(OOOIMessagePumpController)
		OOOImplement(OOOIMessageListener)
	OOOImplementsEnd
	OOOExports
		OOOExport(void, start)
	OOOExportsEnd
OOODeclareEnd

OOOPrivateData
	OOOMessagePump * pMessagePump;
	unsigned int uHandledCount;
OOOPrivateDataEnd

OOODestructor
{
	OOODestroy(OOOF(pMessagePump));
}
OOODestructorEnd

OOOMethod(void, stopped)
{
	/*
	 * First 2 messages should have been handled
	 * twice, the next 3 only once. Thus OOOF(uHandledCount)
	 * should be 7
	 */
	OOOCheck(OOOF(uHandledCount) == 7);

	/* stop should return FALSE if already stopped */
	OOOCheck(!OOOCall(OOOF(pMessagePump), stop));
}
OOOMethodEnd

OOOMethod(bool, onMessage, o_message * pMessage)
{
	bool bHandled = FALSE;
	if (O_msg_class(pMessage) == 10000)
	{
		OOOF(uHandledCount)++;
		if (O_msg_type(pMessage) == 2)
		{
			/* remove self from message handlers once */
			OOOCall(OOOF(pMessagePump), removeListener, OOOCast(OOOIMessageListener, OOOThis));
			bHandled = TRUE;
		}
		else if (O_msg_type(pMessage) == 3)
		{
			/* stop should return TRUE if stopped OK */
			OOOCheck(OOOCall(OOOF(pMessagePump), stop));
			bHandled = TRUE;
		}
		else
		{
			/* allow other messages to be handled by other handlers */
			bHandled = FALSE;
		}
	}
	return bHandled;
}
OOOMethodEnd

OOOMethod(void, started)
{
	o_message tMessage;

	// Add self as message handler twice
	OOOCall(OOOF(pMessagePump), addListener, OOOCast(OOOIMessageListener, OOOThis));
	OOOCall(OOOF(pMessagePump), addListener, OOOCast(OOOIMessageListener, OOOThis));

	// Post some messages
	tMessage.msg_class = 10000;
	tMessage.type = 1;
	assert(O_post_message(&tMessage) == GOOD);
	tMessage.msg_class = 10000;
	tMessage.type = 1;
	assert(O_post_message(&tMessage) == GOOD);
	tMessage.msg_class = 10000;
	tMessage.type = 2;
	assert(O_post_message(&tMessage) == GOOD);
	tMessage.msg_class = 10000;
	tMessage.type = 1;
	assert(O_post_message(&tMessage) == GOOD);
	tMessage.msg_class = 10000;
	tMessage.type = 3;
	assert(O_post_message(&tMessage) == GOOD);

	/* start should return FALSE if already started */
	OOOCheck(!OOOCall(OOOF(pMessagePump), start, OOOCast(OOOIMessagePumpController, OOOThis)));
}
OOOMethodEnd

OOOMethod(void, start)
{
	/* start should return TRUE if started OK */
	OOOCheck(OOOCall(OOOF(pMessagePump), start, OOOCast(OOOIMessagePumpController, OOOThis)));
}
OOOMethodEnd

OOOConstructor()
{
#define OOOInterface OOOIMessagePumpController
	OOOMapVirtuals
		OOOMapVirtual(started)
		OOOMapVirtual(stopped)
	OOOMapVirtualsEnd
#undef OOOInterface

#define OOOInterface OOOIMessageListener
	OOOMapVirtuals
		OOOMapVirtual(onMessage)
	OOOMapVirtualsEnd
#undef OOOInterface

	OOOMapMethods
		OOOMapMethod(start)
	OOOMapMethodsEnd

	OOOF(pMessagePump) = OOOConstruct(OOOMessagePump);
}
OOOConstructorEnd
#undef OOOClass

OOOTest(OOOMessagePump)
{
	MessagePumpTest * pMessagePumpTest = OOOConstruct(MessagePumpTest);
	OOOCall(pMessagePumpTest, start);
	OOODestroy(pMessagePumpTest);
}
