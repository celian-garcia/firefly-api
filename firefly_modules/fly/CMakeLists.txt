if (NOT TARGET ${FLY_MODULE_TARGET})

    ## Dependencies ## ====================================================================
    find_package(OpenCV REQUIRED)

    # Fly Library initialization
    # TODO : refactor Fly library to avoid this
    set(Fly_INCLUDE_DIRS "${Fly_DIR}/include")
    set(Fly_LIB_DIRS1 "${Fly_DIR}/build/debug/lib")
    set(Fly_LIB_DIRS2 "${Fly_DIR}/build/lib")
    set(Fly_LIBRARY Fly)

    # Get FIREFLY CORE include directories
    get_target_property(FIREFLY_CORE_INCLUDE_DIRS ${FIREFLY_CORE_TARGET} INCLUDE_DIRECTORIES)
    ## ============ ## ====================================================================


    ## Target definition ## ================================================================
    add_library(${FLY_MODULE_TARGET}
            src/api/FlyHandler.cpp
            include/fly_module/api/FlyHandler.hpp
            src/model/Cloud3DModel.cpp
            include/fly_module/model/Cloud3DModel.hpp
            src/model/Point3DModel.cpp
            include/fly_module/model/Point3DModel.hpp
            src/model/beans/Cloud3DBean.cpp
            include/fly_module/model/beans/Cloud3DBean.hpp
            src/model/beans/Point3DBean.cpp
            include/fly_module/model/beans/Point3DBean.hpp
            src/workers/FlyCloudPopulation.cpp
            include/fly_module/workers/FlyCloudPopulation.hpp)

    target_link_libraries(${FLY_MODULE_TARGET}
            ${Fly_LIBRARY}
            ${OpenCV_LIBS})

    target_include_directories(${FLY_MODULE_TARGET}
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
            PRIVATE ${FIREFLY_CORE_INCLUDE_DIRS}
            PRIVATE ${Fly_INCLUDE_DIRS})

    set_target_properties(${FLY_MODULE_TARGET} PROPERTIES LINKER_LANGUAGE CXX)
    ## ============ ## ====================================================================


    ## FIREFLY CORE target dependency ## ================================================================
    add_dependencies(${FLY_MODULE_TARGET} ${FIREFLY_CORE_TARGET})
    ## ========================= ## ================================================================

endif ()


