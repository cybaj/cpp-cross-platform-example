cmake_minimum_required(VERSION 3.10)
project(MyTestApp)

add_executable(MyTestApp main.cpp)

# Linking your library
find_library(MY_STANDALONE_UE_LIBRARY MyStandaloneUELibrary PATHS ../../build)
target_link_libraries(MyTestApp PRIVATE ${MY_STANDALONE_UE_LIBRARY})

# Include directories for your library
target_include_directories(MyTestApp PRIVATE ../../include)

