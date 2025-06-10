file(GLOB_RECURSE HLSL_DECOMPILER_FILES CONFIGURE_DEPENDS 
        "${CMAKE_CURRENT_LIST_DIR}/include/*.h"
        "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_executable(CMD_Decompiler ${HLSL_DECOMPILER_FILES})
target_link_libraries(CMD_Decompiler PUBLIC d3dcompiler)
target_include_directories(CMD_Decompiler PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include")
target_compile_definitions(CMD_Decompiler PRIVATE -DCRC32C_STATIC)
target_compile_definitions(CMD_Decompiler PRIVATE -D_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES)
target_compile_definitions(CMD_Decompiler PRIVATE -D_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT)
target_compile_definitions(CMD_Decompiler PRIVATE -D_USRDLL)
target_compile_definitions(CMD_Decompiler PRIVATE -D_WIN32_WINNT=0x600)
if(NOT MSVC)
        target_compile_options(CMD_Decompiler PRIVATE -Wall -Wextra -Wpedantic)
endif()

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
