cmake_minimum_required(VERSION 3.2)
project(Firefly)

find_package(PostgreSQL REQUIRED)
link_directories(${PostgreSQL_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -DUSE_BOOST_REGEX -DWIN32_LEAN_AND_MEAN")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

enable_testing()

# Target names
set(FIREFLY_LAUNCHER_TARGET FIREFLY_LAUNCHER)
set(FIREFLY_CORE_TARGET FIREFLY_CORE)
set(SIMPLE_WEB_SERVER_TARGET SIMPLE_WEB_SERVER)
set(JSON_TARGET JSON)
set(FLY_MODULE_TARGET FLY_MODULE)
set(CV_MODULE_TARGET CV_MODULE)
set(DEPLOY_RESOURCES_TARGET DEPLOY_RESOURCES)

# Add subdirectory. Beware the order.
add_subdirectory(lib)
add_subdirectory(firefly_core)
add_subdirectory(firefly_modules)
add_subdirectory(firefly_launcher)
add_subdirectory(test)

# Create the resources deployment target

add_custom_target(${DEPLOY_RESOURCES_TARGET}
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
        COMMENT "======== Deploying resources folder =======")