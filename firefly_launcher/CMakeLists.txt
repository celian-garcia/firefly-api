if (NOT TARGET ${FIREFLY_LAUNCHER_TARGET})

    message(STATUS "=========== START OF '${FIREFLY_LAUNCHER_TARGET}' target configuration ==============")

    ## Dependencies ## ====================================================================
    # External libraries initialization
    find_package(OpenCV REQUIRED)

    # Get FIREFLY CORE include directories
    get_target_property(FIREFLY_CORE_INCLUDE_DIRS ${FIREFLY_CORE_TARGET} INCLUDE_DIRECTORIES)
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
    add_executable(${FIREFLY_LAUNCHER_TARGET}
            src/main.cpp
            src/server/Server.cpp
            include/firefly/server/Server.hpp
            include/firefly/config/ServerConfig.hpp
            include/firefly/config/DatabaseConfig.hpp include/firefly/config/DatabaseConfig.hpp)

    # Installation
    install(TARGETS ${FIREFLY_LAUNCHER_TARGET} DESTINATION bin)
    install(DIRECTORY include/ DESTINATION include)

    # Fix socket issues in windows
    if (MINGW)
        target_link_libraries(${FIREFLY_LAUNCHER_TARGET} ws2_32 wsock32)
    endif ()

#    link_directories(${PostgreSQL_LIBRARY_DIRS})
    target_link_libraries(${FIREFLY_LAUNCHER_TARGET}
            ${FIREFLY_CORE_TARGET})

    target_include_directories(${FIREFLY_LAUNCHER_TARGET}
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
            PRIVATE ${FIREFLY_CORE_INCLUDE_DIRS})

    set_property(TARGET ${FIREFLY_LAUNCHER_TARGET} PROPERTY CXX_STANDARD 17)
    ## ================ ## ====================================================================


    ## 3rd party dependencies ## ====================================================================
    add_dependencies(${FIREFLY_LAUNCHER_TARGET} ${FIREFLY_CORE_TARGET} ${DEPLOY_RESOURCES_TARGET})
    ## ====================== ## ====================================================================


    ## Modules dependencies ## ====================================================================
    if (WITH_FLY_MODULE)
        message(STATUS "=========== >> LINK '${FLY_MODULE_TARGET}' target to '${FIREFLY_LAUNCHER_TARGET}' ==============")
        add_dependencies(${FIREFLY_LAUNCHER_TARGET} ${FLY_MODULE_TARGET})
        target_compile_options(${FIREFLY_LAUNCHER_TARGET}
                PRIVATE -DWITH_FLY_MODULE)
        target_link_libraries(${FIREFLY_LAUNCHER_TARGET}
                ${FLY_MODULE_TARGET})
    endif ()

    if (WITH_CV_MODULE)
        message(STATUS "=========== >> LINK '${CV_MODULE_TARGET}' target to '${FIREFLY_LAUNCHER_TARGET}' ==============")
        add_dependencies(${FIREFLY_LAUNCHER_TARGET} ${CV_MODULE_TARGET})
        target_compile_options(${FIREFLY_LAUNCHER_TARGET}
                PRIVATE -DWITH_CV_MODULE)
        target_link_libraries(${FIREFLY_LAUNCHER_TARGET}
                ${CV_MODULE_TARGET})
    endif ()
    ## ==================== ## ====================================================================

    message(STATUS "=========== END OF '${FIREFLY_LAUNCHER_TARGET}' target configuration ==============")

endif ()


