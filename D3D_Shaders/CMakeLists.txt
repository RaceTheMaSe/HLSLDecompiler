file(GLOB_RECURSE D3D_SHADERS_FILES CONFIGURE_DEPENDS 
        "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_executable(D3D_Shaders ${D3D_SHADERS_FILES})
target_link_libraries(D3D_Shaders PRIVATE BinaryDecompiler)