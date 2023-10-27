#include "MyStandaloneUELibrary/MyLibraryHeader.h"

void MyStandaloneUELibrary::MyLibraryClass::MyFunction()
{
    PlatformFunction();
}

void MyStandaloneUELibrary::MyLibraryClass::PlatformFunction()
{
    #if defined(_WIN32)
    WindowsFunction();
    #elif defined(__APPLE__) && TARGET_OS_MAC
    MacFunction();
    #elif defined(__APPLE__) && TARGET_OS_IPHONE
    iOSFunction();
    #elif defined(__ANDROID__)
    AndroidFunction();
    #endif
}

#if defined(_WIN32)
void MyStandaloneUELibrary::MyLibraryClass::WindowsFunction()
{
    // Windows-specific code here...
}


#elif defined(__APPLE__) && TARGET_OS_MAC
void MyStandaloneUELibrary::MyLibraryClass::MacFunction()
{
    // Mac-specific code here...
}

#elif defined(__APPLE__) && TARGET_OS_IPHONE
void MyStandaloneUELibrary::MyLibraryClass::iOSFunction()
{
    // iOS-specific code here...
}

#elif defined(__ANDROID__)
void MyStandaloneUELibrary::MyLibraryClass::AndroidFunction()
{
    // Android-specific code here...
}
#endif
