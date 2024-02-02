file(GLOB_RECURSE BINARY_DECOMPILER_FILES CONFIGURE_DEPENDS 
        "${CMAKE_CURRENT_LIST_DIR}/include/*.h"
        "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_library(BinaryDecompiler STATIC ${BINARY_DECOMPILER_FILES})
target_link_libraries(BinaryDecompiler PUBLIC D3DCompiler.lib)
target_include_directories(BinaryDecompiler PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

set_target_properties(BinaryDecompiler PROPERTIES
                CXX_STANDARD 14)
set_target_properties(BinaryDecompiler PROPERTIES
                CMAKE_CXX_STANDARD_REQUIRED ON)
set_target_properties(BinaryDecompiler PROPERTIES
                CXX_EXTENSIONS OFF)
set_target_properties(BinaryDecompiler PROPERTIES 
                ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/lib")
set_target_properties(BinaryDecompiler PROPERTIES 
                ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/lib")