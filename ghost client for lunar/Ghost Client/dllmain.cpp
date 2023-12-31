// dllmain.cpp : Defines the entry point for the DLL application.
#include <windows.h>

#include <jni.h>

#include "Java.h"

#include <chrono>
#include <thread>

FILE* file = nullptr;

void init(void* instance)
{
    jsize count;
    if (JNI_GetCreatedJavaVMs(&lc->vm, 1, &count) != JNI_OK || count == 0) return;
    jint res = lc->vm->GetEnv((void**)&lc->env, JNI_VERSION_1_8);

    if (res == JNI_EDETACHED) res = lc->vm->AttachCurrentThread((void**)&lc->env, nullptr);

    if (lc->env != nullptr)
    {
        lc->GetLoadedClasses();

        while (true)
        {
            if (GetAsyncKeyState(VK_END)) break;

            std::this_thread::sleep_for(std::chrono::milliseconds(8));
        }
    }

    fclose(file);
    FreeConsole();

    ShowWindow(GetConsoleWindow(), SW_HIDE);

    FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    DisableThreadLibraryCalls(hModule);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        AllocConsole();
        freopen_s(&file, "CONOUT$", "w", stdout);

        CloseHandle(CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(init), hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

