if (NOT TARGET ${FIREFLY_CORE_TARGET})

    SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

    if (MINGW)
        set(Boost_COMPILER -mgw71)
    endif ()

    ## Dependencies ## ====================================================================
    # External libraries initialization
    find_package(OpenCV REQUIRED)
    find_package(Boost 1.62.0 COMPONENTS system thread filesystem date_time regex REQUIRED)
    find_package(PostgreSQL REQUIRED)
    find_library(PQTYPES_LIB NAMES pqtypes)

    get_target_property(SIMPLE_WEB_SERVER_INCLUDE_DIRS ${SIMPLE_WEB_SERVER_TARGET} INCLUDE_DIRECTORIES)
    get_target_property(JSON_INCLUDE_DIRS ${JSON_TARGET} INCLUDE_DIRECTORIES)
    ## ============ ## ====================================================================


    ## Target definition ## ====================================================================
    # TODO : list explicitly all used files
    file(GLOB_RECURSE FIREFLY_CORE_FILES *.cpp *.hpp)
    add_library(${FIREFLY_CORE_TARGET}
            ${FIREFLY_CORE_FILES}
            src/data/Module.cpp
            include/firefly/core/data/Module.hpp
            src/data/Task.cpp
            include/firefly/core/data/Task.hpp
            src/data/ProcessingTypeJson.cpp
            include/firefly/core/data/ProcessingType.hpp
            src/model/TaskModel.cpp
            include/firefly/core/model/TaskModel.hpp
            src/config/DataCommonStore.cpp
            include/firefly/core/config/DataCommonStore.hpp
            src/data/TaskBuilder.cpp
            include/firefly/core/data/TaskBuilder.hpp
            src/model/interpreters/PGResultInterpreter.cpp
            include/firefly/core/model/interpreters/PGResultInterpreter.hpp
            src/model/interpreters/TaskInterpreter.cpp
            include/firefly/core/model/interpreters/TaskInterpreter.hpp
            src/model/beans/Point3DBean.cpp
            include/firefly/core/model/beans/Point3DBean.hpp
            src/model/interpreters/Point3DInterpreter.cpp
            include/firefly/core/model/interpreters/Point3DInterpreter.hpp
            src/model/OperationModel.cpp
            include/firefly/core/model/OperationModel.hpp
            include/firefly/core/data/OperationType.hpp
            src/model/interpreters/OperationInterpreter.cpp
            include/firefly/core/model/interpreters/OperationInterpreter.hpp
            include/firefly/core/data/OperationElement.hpp
            include/firefly/core/utils/ConcurrentOperationQueue.hpp)

    # Fix socket issues in windows
    if (MINGW)
        target_link_libraries(${FIREFLY_CORE_TARGET} ws2_32 wsock32)
    endif ()

    target_link_libraries(${FIREFLY_CORE_TARGET}
            ${OpenCV_LIBS}
            ${Boost_LIBRARIES}
            ${PostgreSQL_LIBRARIES}
            ${PQTYPES_LIB})

    target_include_directories(${FIREFLY_CORE_TARGET}
            PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
            PRIVATE ${SIMPLE_WEB_SERVER_INCLUDE_DIRS}
            PRIVATE ${JSON_INCLUDE_DIRS}
            PRIVATE ${Boost_INCLUDE_DIRS}
            PRIVATE ${PostgreSQL_INCLUDE_DIRS}
            PRIVATE ${OpenCV_INCLUDE_DIRS})

    set_property(TARGET ${FIREFLY_CORE_TARGET} PROPERTY CXX_STANDARD 17)
    ## ================ ## ====================================================================

    ## Target tests ## ================================================================
    add_subdirectory(test)
    ## ============ ## ====================================================================

    ## 3rd party dependencies ## ====================================================================
    add_dependencies(${FIREFLY_CORE_TARGET}
            ${SIMPLE_WEB_SERVER_TARGET}
            ${JSON_TARGET})
    ## ====================== ## ====================================================================

endif()


