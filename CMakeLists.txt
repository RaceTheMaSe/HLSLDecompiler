cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(HLSLDecompiler LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")

# Common files
set(HLSL_COMMON_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/common" CACHE PATH "Common header file directory" FORCE)

# Subdirectories
add_subdirectory(BinaryDecompiler)
add_subdirectory(D3D_Shaders)
add_subdirectory(HLSLDecompiler)