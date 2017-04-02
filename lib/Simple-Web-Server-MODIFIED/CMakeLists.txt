if (NOT TARGET ${SIMPLE_WEB_SERVER_TARGET})

    ## Target definition ## ===================================================================
    add_library(${SIMPLE_WEB_SERVER_TARGET}
            ${CMAKE_CURRENT_SOURCE_DIR}/include/simple_web_server/server_http.hpp)

    set_target_properties(${SIMPLE_WEB_SERVER_TARGET} PROPERTIES LINKER_LANGUAGE CXX)

    target_include_directories(${SIMPLE_WEB_SERVER_TARGET}
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    ## ================= ## ===================================================================

endif ()