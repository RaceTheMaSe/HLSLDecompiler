file(GLOB_RECURSE BINARY_DECOMPILER_FILES CONFIGURE_DEPENDS 
        "${CMAKE_CURRENT_LIST_DIR}/include/*.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_library(BinaryDecompiler STATIC ${BINARY_DECOMPILER_FILES})
target_link_libraries(BinaryDecompiler PUBLIC D3DCompiler.lib)
target_include_directories(BinaryDecompiler PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
target_include_directories(BinaryDecompiler PUBLIC "${HLSL_COMMON_INCLUDE_DIR}")