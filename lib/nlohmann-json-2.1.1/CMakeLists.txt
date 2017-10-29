if (NOT TARGET ${JSON_TARGET})

    ## Target definition ## ===================================================================
    add_library(${JSON_TARGET}
            ${CMAKE_CURRENT_SOURCE_DIR}/include/json/json.hpp)

    set_target_properties(${JSON_TARGET} PROPERTIES LINKER_LANGUAGE CXX)

    target_include_directories(${JSON_TARGET}
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    ## ================= ## ===================================================================

endif ()