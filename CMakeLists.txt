cmake_minimum_required(VERSION 3.18)
set(PROJECT_NAME Zadanie_Radmor)
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14 CACHE STRING "The C++ standard to use")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_LIBRARY_TYPE SHARED)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug mode cxxflags: ${CMAKE_CXX_FLAGS} cxx_flags_debug: ${CMAKE_CXX_FLAGS_DEBUG}")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release mode cxxflags: ${CMAKE_CXX_FLAGS} cxx_flags_release: ${CMAKE_CXX_FLAGS_RELEASE}")
endif()

find_package(Threads REQUIRED)

add_subdirectory(libs)
add_subdirectory(app)

aux_source_directory(. MAIN_FILES)

add_executable(main ${MAIN_FILES})
target_link_libraries(main LIB_RandomEngine)
#target_compile_features(main PUBLIC cxx_std_14)
