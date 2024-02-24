file(GLOB_RECURSE HLSL_DECOMPILER_FILES CONFIGURE_DEPENDS 
        "${CMAKE_CURRENT_LIST_DIR}/include/*.h"
        "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_executable(CMD_Decompiler ${HLSL_DECOMPILER_FILES})
target_link_libraries(CMD_Decompiler PUBLIC D3DCompiler.lib)
target_include_directories(CMD_Decompiler PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include")
target_compile_definitions(CMD_Decompiler PRIVATE -DCRC32C_STATIC)
target_compile_definitions(CMD_Decompiler PRIVATE -D_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES)
target_compile_definitions(CMD_Decompiler PRIVATE -D_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT)
target_compile_definitions(CMD_Decompiler PRIVATE -D_USRDLL)

set_target_properties(CMD_Decompiler PROPERTIES
                CXX_STANDARD 14)
set_target_properties(CMD_Decompiler PROPERTIES
                CMAKE_CXX_STANDARD_REQUIRED ON)
set_target_properties(CMD_Decompiler PROPERTIES
                CXX_EXTENSIONS OFF)
set_target_properties(CMD_Decompiler PROPERTIES
                ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/bin")
set_target_properties(CMD_Decompiler PROPERTIES
                ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin")
