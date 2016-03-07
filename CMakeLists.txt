cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("bogeyman")

if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
  set(CMAKE_C_FLAGS   "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG")  


include_directories(inc/)

set(SAMPLES_DIR samples)
add_subdirectory(${SAMPLES_DIR})

install (DIRECTORY inc/ DESTINATION include)
