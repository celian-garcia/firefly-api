cmake_minimum_required(VERSION 3.6)
project(FIREFLY)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# External libraries initialization
find_package( OpenCV REQUIRED )
find_package( Boost COMPONENTS system thread date_time regex serialization REQUIRED )

# Fly Library initialization
set(Fly_INCLUDE_DIRS "${Fly_DIR}/include")
set(Fly_LIB_DIRS "${Fly_DIR}/build/debug/lib")
set(Fly_LIBRARY Fly)

# Firefly executable variables
set(FIREFLY_EXEC_NAME Firefly)
file(GLOB_RECURSE FIREFLY_SOURCES src/* )
file(GLOB_RECURSE FIREFLY_HEADERS include/*)

# Firefly executable definition
link_directories(${Fly_LIB_DIRS})
message(STATUS ${Fly_INCLUDE_DIRS})
include_directories(include
        ${Boost_INCLUDE_DIRS}  # Necessary because we use asio which is include-only project
        ${Fly_INCLUDE_DIRS})
add_executable(${FIREFLY_EXEC_NAME} ${FIREFLY_SOURCES} ${FIREFLY_HEADERS})
target_link_libraries (${FIREFLY_EXEC_NAME}
        ${OpenCV_LIBS}
        ${Boost_SYSTEM_LIBRARY} 
        ${Boost_THREAD_LIBRARY} 
        ${Boost_DATE_TIME_LIBRARY} 
        ${Boost_REGEX_LIBRARY} 
        ${Boost_SERIALIZATION_LIBRARY}
        ${Fly_LIBRARY})

# Fix socket issues in windows
if(MINGW)
    target_link_libraries(${FIREFLY_EXEC_NAME} ws2_32 wsock32)
endif()