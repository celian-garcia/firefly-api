cmake_minimum_required(VERSION 3.2)
project(FIREFLY)
SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -DUSE_BOOST_REGEX -DWIN32_LEAN_AND_MEAN")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# External libraries initialization
find_package( OpenCV REQUIRED )
set(BOOST_COMPONENTS system thread filesystem date_time regex)
find_package(Boost 1.53.0 COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
find_package(PostgreSQL REQUIRED)


# Fly Library initialization
set(Fly_INCLUDE_DIRS "${Fly_DIR}/include")
set(Fly_LIB_DIRS "${Fly_DIR}/build/debug/lib")
set(Fly_LIBRARY Fly)

# Firefly executable variables
set(FIREFLY_EXEC_NAME Firefly)
file(GLOB_RECURSE FIREFLY_SOURCES src/* )
file(GLOB_RECURSE FIREFLY_HEADERS include/*)
file(GLOB_RECURSE sources_to_discard src/model )

# Exclude temporary unused files
list(FILTER FIREFLY_SOURCES EXCLUDE REGEX .+controller.+)
list(FILTER FIREFLY_SOURCES EXCLUDE REGEX .+model.+)
list(FILTER FIREFLY_SOURCES EXCLUDE REGEX .+operation.+)
list(FILTER FIREFLY_SOURCES EXCLUDE REGEX .+modules/opencv.+)
list(FILTER FIREFLY_HEADERS EXCLUDE REGEX .+controller.+)
list(FILTER FIREFLY_HEADERS EXCLUDE REGEX .+model.+)
list(FILTER FIREFLY_HEADERS EXCLUDE REGEX .+operation.+)
list(FILTER FIREFLY_HEADERS EXCLUDE REGEX .+modules/opencv.+)

# Firefly executable definition
link_directories(${Fly_LIB_DIRS} ${PostgreSQL_LIBRARY_DIRS})
include_directories(include
        ${Boost_INCLUDE_DIRS}  # Necessary because we use asio which is include-only project
        ${Fly_INCLUDE_DIRS}
        ${PostgreSQL_INCLUDE_DIRS})
add_executable(${FIREFLY_EXEC_NAME} ${FIREFLY_SOURCES} ${FIREFLY_HEADERS})
target_link_libraries (${FIREFLY_EXEC_NAME}
        ${OpenCV_LIBS}
        ${Boost_LIBRARIES}
        ${Fly_LIBRARY}
        ${PostgreSQL_LIBRARIES})

# Fix socket issues in windows
if(MINGW)
    target_link_libraries(${FIREFLY_EXEC_NAME} ws2_32 wsock32)
endif()

# Create the resources deployment target
add_custom_target(deploy_resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
    COMMENT "======== Deploying resources folder =======")
add_dependencies(${FIREFLY_EXEC_NAME} deploy_resources)