#include "MyStandaloneUELibrary/MyLibraryHeader.h"
#include <iostream>

#if defined(_WIN32)
#include <Windows.h>
#include <tchar.h>
#elif defined(__APPLE__)
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE
#include <Foundation/Foundation.h>
#endif
#elif defined(__ANDROID__)
#include <android/log.h>
#endif

void MyStandaloneUELibrary::MyLibraryClass::MyFunction()
{
    PlatformFunction();
}

void MyStandaloneUELibrary::MyLibraryClass::PlatformFunction()
{
    #if defined(_WIN32)
    WindowsFunction();
    #elif defined(__APPLE__) && TARGET_OS_MAC
    MacOSFunction();
    #elif defined(__APPLE__) && TARGET_OS_IPHONE
    iOSFunction();
    #elif defined(__ANDROID__)
    AndroidFunction();
    #endif
}

#if defined(_WIN32)
void MyStandaloneUELibrary::MyLibraryClass::WindowsFunction()
{
    OutputDebugString(_T"Hello World from Windows!\n");
}

#elif defined(__APPLE__) && TARGET_OS_MAC
void MyStandaloneUELibrary::MyLibraryClass::MacOSFunction()
{
    printf("Hello World from macOS!\n");
}

#elif defined(__APPLE__) && TARGET_OS_IPHONE
void MyStandaloneUELibrary::MyLibraryClass::iOSFunction()
{
    NSLog(@"Hello World from iOS!");
}

#elif defined(__ANDROID__)
void MyStandaloneUELibrary::MyLibraryClass::AndroidFunction()
{
    __android_log_print(ANDROID_LOG_INFO, "MyStandaloneUELibrary", "Hello World from Android!");
}
#endif

