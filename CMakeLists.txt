cmake_minimum_required(VERSION 3.6)
project(firefly)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_ROOT}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_ROOT}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin")

# External libraries initialization
find_package( OpenCV REQUIRED )
find_package( Boost COMPONENTS system thread date_time regex serialization REQUIRED )
set(Fly_INCLUDE_DIRS "${Fly_DIR}/src")
set(Fly_LIB_DIRS "${Fly_DIR}/lib")

# Include directories
include_directories(include
        ${Boost_INCLUDE_DIRS}  # Necessary because we use asio which is include-only project
        ${Fly_INCLUDE_DIRS})

# Link directories
link_directories(${Fly_LIB_DIRS})

# Source files to give to the executable
file( GLOB_RECURSE
        source_files
        src/*
        include/*)

# Create the executable target "firefly"
add_executable(firefly
        ${source_files})

# Link the libraries with the "firefly" target
target_link_libraries (firefly
        ${OpenCV_LIBS}
        ${Boost_ASIO_LIBRARY}
        Fly)