OOOCode-MessagePump
===================

An OOOCode module for managing asynchronous messages

## Features

- Should be able to start and stop the message pump
- Should be able to add and remove message handlers

## API

The API exposes 2 interfaces

- ```OOOIMessagePumpController```
	- intended for implementation by a parent application to start and stop the message pump
- ```OOOIMessageListener```
	- intended for use by components that need to listen for asynchrounous messages

To implement an OOOIMessagePumpController...

```C
#include "OOOMessagePump.h"

#define OOOClass MyApplication
OOODeclare()
	OOOImplements
		OOOImplement(OOOIMessagePumpController)
	OOOImplementsEnd
	OOOExports
		OOOExport(void, start)
		OOOExport(void, stop)
	OOOExportsEnd
OOODeclareEnd

OOOPrivateData
	OOOMessagePump * pMessagePump;
OOOPrivateDataEnd

OOODestructor
{
	OOODestroy(OOOF(pMessagePump));
}
OOODestructorEnd

OOOMethod(void, stopped)
{
	/*
	Message pump has stopped
	*/
}
OOOMethodEnd

OOOMethod(void, stop)
{
	OOOCall(OOOF(pMessagePump), stop);
}
OOOMethodEnd

OOOMethod(void, started)
{
	/*
	Message pump has now started. Can continue
	constructing the application components that
	require a running message pump
	*/
}
OOOMethodEnd

OOOMethod(void, start)
{
	OOOCall(OOOF(pMessagePump), start, OOOCast(OOOIMessagePumpController, OOOThis));
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

	OOOMapMethods
		OOOMapMethod(start)
		OOOMapMethod(stop)
	OOOMapMethodsEnd

	OOOF(pMessagePump) = OOOConstruct(OOOMessagePump);
}
OOOConstructorEnd
#undef OOOClass
```

To implement an OOOIMessageListener...

```C
#include "OOOMessagePump.h"

#define OOOClass MyAsynchronousComponent
OOODeclare()
	OOOImplements
		OOOImplement(OOOIMessageListener)
	OOOImplementsEnd
	OOOExports
	OOOExportsEnd
OOODeclareEnd

OOOPrivateData
	OOOMessagePump * pMessagePump;
OOOPrivateDataEnd

OOODestructor
{
	OOOCall(pMessagePump, removeListener, OOOCast(OOOIMessageListener, OOOThis));
}
OOODestructorEnd

OOOMethod(bool, onMessage, o_message * pMessage)
{
	bool bHandled = FALSE;

	/*
	Handle the message
	*/

	return bHandled;
}
OOOMethodEnd

OOOConstructor(OOOMessagePump pMessagePump)
{
#define OOOInterface OOOIMessageListener
	OOOMapVirtuals
		OOOMapVirtual(onMessage)
	OOOMapVirtualsEnd
#undef OOOInterface

	OOOMapMethods
	OOOMapMethodsEnd

	OOOF(pMessagePump) = pMessagePump;
	OOOCall(pMessagePump, addListener, OOOCast(OOOIMessageListener, OOOThis));
}
OOOConstructorEnd
#undef OOOClass
```

## Roadmap

- Nothing planned

## Contributing

In lieu of a formal styleguide, take care to maintain the existing coding style. Add unit tests for any new or changed functionality.

## Prerequisites

- OpenTV SDK C2.2 from http://community.opentv.com

## Initialising

This projects references sub-modules so after cloning the repository...

```
git submodule init
git submodule update
```

Then the easiest way to work with the project in the OpenTV IDE...

1. Create a new workspace in the root of the project
1. In the IDE choose **File/Import...**
1. In the resulting dialog choose **General/Existing Projects Into Workspace** and press **Next**
1. Choose the **Select Root Directory:** Radio button and **Browse...** to the root of the project
1. A number of projects may be listed under **Projects**
1. Select the projects in the root, deselect those under the submodules folder and then click **Finish**
1. You should then be able to build the OpenTV projects by choosing **Project/Build All**

After you have built the projects at least once run the test application in the Virtual Set top box by...

1. Choosing the **MessagePumpFlow** project on the left
1. Pressing the green **Run** button at the top
1. In the resulting dialog choose **Local OpenTV Application** and press **OK**

## Release History
_(Nothing yet)_

## License
Copyright (c) 2012 Peter Halliday  
Licensed under the MIT license.