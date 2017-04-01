# Create the resources deployment target
add_custom_target(deploy_resources
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
        COMMENT "======== Deploying resources folder =======")
add_dependencies(${FIREFLY_EXEC_NAME} deploy_resources)