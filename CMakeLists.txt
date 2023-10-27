cmake_minimum_required(VERSION 3.10)
project(MyStandaloneUELibrary)

set(CMAKE_CXX_STANDARD 17)

# Global configurations
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Platform-specific configurations
if(WIN32)
    # Windows-specific build settings here...
    add_definitions(-DMYLIBRARY_EXPORTS)  # Define the export symbol for __declspec(dllexport)

elseif(APPLE)
    # Universal for both iOS and macOS
    set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")  # Example architectures for macOS and iOS

    if(IOS)
        # iOS-specific build settings here...
        set(CMAKE_XCODE_EFFECTIVE_PLATFORMS "-iphoneos;-iphonesimulator")
        set(CMAKE_IOS_INSTALL_COMBINED YES)
    else()
        # macOS-specific build settings here...
    endif()

elseif(ANDROID)
    # Android-specific build settings here...
    set(CMAKE_ANDROID_NDK /path/to/your/android-ndk)  # Adjust this path
    set(CMAKE_ANDROID_ARCH_ABI armeabi-v7a)  # Example ABI; you can adjust or add more
    set(CMAKE_ANDROID_NATIVE_API_LEVEL android-21)  # Minimum API level
    # Additional settings for Android might include STL type, exceptions, etc.
endif()

# Build the library
add_library(MyStandaloneUELibrary SHARED ${SOURCES})

# Link libraries if any, for example:
# target_link_libraries(MyStandaloneUELibrary anotherLibrary)

# If you want to install the library to a specific location, you can add:
# install(TARGETS MyStandaloneUELibrary DESTINATION /path/to/your/destination)

