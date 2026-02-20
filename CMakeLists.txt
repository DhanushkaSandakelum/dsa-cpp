cmake_minimum_required(VERSION 3.16)

project(dsa_cpp
    VERSION 1.0
    DESCRIPTION "Data Structures and Algorithms in C++"
    LANGUAGES CXX
)

# ---------------------------------------
# Global Compiler Settings
# ---------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------------------
# Output Directories
# ---------------------------------------
# All executables move to build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ---------------------------------------
# Include src directory for headers
# ---------------------------------------
include_directories(${PROJECT_SOURCE_DIR}/src)

# ---------------------------------------
# Examples
# ---------------------------------------

# --------------------------------------------------
# IMPORTANT:
# Keep ONLY ONE example active at a time.
# Comment others when switching.
# --------------------------------------------------

# --- Section 3: Static Array Demo
add_executable(static_array_demo
    examples/section3/static_array_demo.cpp
)