if (NOT TARGET ${FLY_MODULE_TARGET})

    message(STATUS "=========== START OF '${FLY_MODULE_TARGET}' target configuration ==============")

    ## Dependencies ## ====================================================================
    find_package(PkgConfig REQUIRED)
    find_package(OpenCV REQUIRED)
    pkg_check_modules(Fly REQUIRED fly)

    link_directories(${Fly_LIBRARY_DIRS})

    # Get FIREFLY CORE include directories
    get_target_property(FIREFLY_CORE_INCLUDE_DIRS ${FIREFLY_CORE_TARGET} INCLUDE_DIRECTORIES)
    ## ============ ## ====================================================================

    ## Target definition ## ================================================================
    add_library(${FLY_MODULE_TARGET}
            src/workers/FlyCloudPopulation.cpp
            include/fly_module/workers/FlyCloudPopulation.hpp
            src/data/FlyModule.cpp
            include/fly_module/data/FlyModule.hpp
            src/workers/CloudContainerImpl.cpp
            include/fly_module/workers/CloudContainerImpl.hpp)

    target_link_libraries(${FLY_MODULE_TARGET}
            ${FIREFLY_CORE_TARGET}
            ${OpenCV_LIBS}
            ${Fly_LIBRARIES})

    target_include_directories(${FLY_MODULE_TARGET}
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
            PRIVATE ${FIREFLY_CORE_INCLUDE_DIRS}
            PRIVATE ${Fly_INCLUDE_DIRS})

    set_target_properties(${FLY_MODULE_TARGET} PROPERTIES LINKER_LANGUAGE CXX)
    ## ============ ## ====================================================================

    ## Target tests ## ================================================================
    add_subdirectory(test)
    ## ============ ## ====================================================================

    ## FIREFLY CORE target dependency ## ================================================================
    add_dependencies(${FLY_MODULE_TARGET} ${FIREFLY_CORE_TARGET})
    ## ========================= ## ================================================================

    message(STATUS "=========== END OF '${FLY_MODULE_TARGET}' target configuration ==============")
endif ()


