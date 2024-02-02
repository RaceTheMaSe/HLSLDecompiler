file(GLOB_RECURSE D3D_SHADERS_FILES CONFIGURE_DEPENDS 
        "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_executable(D3D_Shaders ${D3D_SHADERS_FILES})
target_link_libraries(D3D_Shaders PRIVATE BinaryDecompiler)

set_target_properties(D3D_Shaders PROPERTIES
                CXX_STANDARD 14)
set_target_properties(D3D_Shaders PROPERTIES
                CMAKE_CXX_STANDARD_REQUIRED ON)
set_target_properties(D3D_Shaders PROPERTIES
                CXX_EXTENSIONS OFF)
set_target_properties(D3D_Shaders PROPERTIES 
                RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/bin")
set_target_properties(D3D_Shaders PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin")