#pragma once

// Platform-specific symbol export and import macros
#if defined(_WIN32)
    #ifdef MYLIBRARY_EXPORTS
        #define MYLIBRARY_API __declspec(dllexport)
    #else
        #define MYLIBRARY_API __declspec(dllimport)
    #endif
#else
    #define MYLIBRARY_API
#endif

// FIX: temporary workaround
#define TARGET_OS_MAC 0
#define TARGET_OS_IPHONE 0

namespace MyStandaloneUELibrary
{
    class MYLIBRARY_API MyLibraryClass
    {
    public:
        void MyFunction();

    private:
        void PlatformFunction();

        #if defined(_WIN32)
        void WindowsFunction();
        #elif defined(__APPLE__) && TARGET_OS_MAC
        void MacFunction();
        #elif defined(__APPLE__) && TARGET_OS_IPHONE
        void iOSFunction();
        #elif defined(__ANDROID__)
        void AndroidFunction();
        #endif
    };
}

