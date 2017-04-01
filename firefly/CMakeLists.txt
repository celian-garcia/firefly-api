if (NOT TARGET ${FIREFLY_TARGET})

## Dependencies ## ====================================================================
# External libraries initialization
find_package(OpenCV REQUIRED)
find_package(Boost 1.53.0 COMPONENTS system thread filesystem date_time regex REQUIRED)
find_package(PostgreSQL REQUIRED)
get_target_property(SIMPLE_WEB_SERVER_INCLUDE_DIRS ${SIMPLE_WEB_SERVER_TARGET} INCLUDE_DIRECTORIES)
## ============ ## ====================================================================


## Default modules uses ## ====================================================================
if (NOT WITH_FLY_MODULE)
    set(WITH_FLY_MODULE ON)
endif ()

if (NOT WITH_CV_MODULE)
    set(WITH_CV_MODULE OFF)
endif ()
## ==================== ## ====================================================================


## Target definition ## ====================================================================
# TODO : list explicitly all used files
file(GLOB_RECURSE FIREFLY_FILES *.cpp *.hpp)
add_executable(${FIREFLY_TARGET}
        ${FIREFLY_FILES})

# Fix socket issues in windows
if (MINGW)
    target_link_libraries(${FIREFLY_TARGET} ws2_32 wsock32)
endif ()

target_link_libraries(${FIREFLY_TARGET}
        ${OpenCV_LIBS}
        ${Boost_LIBRARIES}
        ${PostgreSQL_LIBRARIES})


target_include_directories(${FIREFLY_TARGET}
        PUBLIC  include
        PRIVATE ${SIMPLE_WEB_SERVER_INCLUDE_DIRS}
        PRIVATE ${Boost_INCLUDE_DIRS}  # Necessary because we use asio which is include-only project
        PRIVATE ${PostgreSQL_INCLUDE_DIRS})

set_property(TARGET ${FIREFLY_TARGET} PROPERTY CXX_STANDARD 11)
## ================ ## ====================================================================


## 3rd party dependencies ## ====================================================================
add_dependencies(${FIREFLY_TARGET} ${SIMPLE_WEB_SERVER_TARGET})
## ====================== ## ====================================================================


## Modules dependencies ## ====================================================================
if (WITH_FLY_MODULE)
    add_dependencies(${FIREFLY_TARGET} ${FLY_MODULE_TARGET})
    target_compile_options(${FIREFLY_TARGET}
            PRIVATE -DWITH_FLY_MODULE)
endif ()

if (WITH_CV_MODULE)
    add_dependencies(${FIREFLY_TARGET} ${CV_MODULE_TARGET})
    target_compile_options(${FIREFLY_TARGET}
            PRIVATE -DWITH_CV_MODULE)
endif ()
## ==================== ## ====================================================================

endif()


