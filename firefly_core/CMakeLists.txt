if (NOT TARGET ${FIREFLY_CORE_TARGET})

    ## Dependencies ## ====================================================================
    # External libraries initialization
    find_package(OpenCV REQUIRED)
    find_package(Boost 1.53.0 COMPONENTS system thread filesystem date_time regex REQUIRED)
    find_package(PostgreSQL REQUIRED)
    get_target_property(SIMPLE_WEB_SERVER_INCLUDE_DIRS ${SIMPLE_WEB_SERVER_TARGET} INCLUDE_DIRECTORIES)
    get_target_property(JSON_INCLUDE_DIRS ${JSON_TARGET} INCLUDE_DIRECTORIES)
    ## ============ ## ====================================================================


    ## Target definition ## ====================================================================
    # TODO : list explicitly all used files
    file(GLOB_RECURSE FIREFLY_CORE_FILES *.cpp *.hpp)
    add_library(${FIREFLY_CORE_TARGET}
            ${FIREFLY_CORE_FILES})

    # Fix socket issues in windows
    if (MINGW)
        target_link_libraries(${FIREFLY_CORE_TARGET} ws2_32 wsock32)
    endif ()

    target_link_libraries(${FIREFLY_CORE_TARGET}
            ${OpenCV_LIBS}
            ${Boost_LIBRARIES}
            ${PostgreSQL_LIBRARIES})


    target_include_directories(${FIREFLY_CORE_TARGET}
            PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
            PRIVATE ${SIMPLE_WEB_SERVER_INCLUDE_DIRS}
            PRIVATE ${JSON_INCLUDE_DIRS}
            PRIVATE ${Boost_INCLUDE_DIRS}  # Necessary because we use asio which is include-only project
            PRIVATE ${PostgreSQL_INCLUDE_DIRS})

    set_property(TARGET ${FIREFLY_CORE_TARGET} PROPERTY CXX_STANDARD 11)
    ## ================ ## ====================================================================


    ## 3rd party dependencies ## ====================================================================
    add_dependencies(${FIREFLY_CORE_TARGET}
            ${SIMPLE_WEB_SERVER_TARGET}
            ${JSON_TARGET})
    ## ====================== ## ====================================================================

endif()


