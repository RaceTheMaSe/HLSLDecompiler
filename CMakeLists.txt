cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(HLSLDecompiler LANGUAGES CXX C)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")

# Subdirectories
add_subdirectory(BinaryDecompiler)
add_subdirectory(D3D_Shaders)
add_subdirectory(HLSLDecompiler)