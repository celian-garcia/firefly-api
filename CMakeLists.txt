cmake_minimum_required(VERSION 3.2)
project(Firefly)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -DUSE_BOOST_REGEX -DWIN32_LEAN_AND_MEAN")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

enable_testing()

# Target names
set(FIREFLY_TARGET FIREFLY)
set(FIREFLY_CORE_TARGET FIREFLY_CORE)
set(SIMPLE_WEB_SERVER_TARGET SIMPLE_WEB_SERVER)
set(JSON_TARGET JSON)
set(FLY_MODULE_TARGET FLY_MODULE)
set(CV_MODULE_TARGET CV_MODULE)

add_subdirectory(lib)
add_subdirectory(firefly)
add_subdirectory(firefly_core)
add_subdirectory(firefly_modules)
add_subdirectory(test)