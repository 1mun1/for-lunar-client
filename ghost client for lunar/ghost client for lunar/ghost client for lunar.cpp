// ghost client for lunar.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ghost client for lunar.h"


// This is an example of an exported variable
GHOSTCLIENTFORLUNAR_API int nghostclientforlunar=0;

// This is an example of an exported function.
GHOSTCLIENTFORLUNAR_API int fnghostclientforlunar(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Cghostclientforlunar::Cghostclientforlunar()
{
    return;
}
