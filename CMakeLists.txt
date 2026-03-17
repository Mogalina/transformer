cmake_minimum_required(VERSION 3.14)

project(transformer C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find all source files
file(GLOB_RECURSE SOURCES "src/*.c")

if(SOURCES)
    # Create the static library
    add_library(transformer STATIC ${SOURCES})

    # Add the include directory
    target_include_directories(transformer PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    )

    # Enable standard warnings
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_C_COMPILER_ID MATCHES "Clang")
        target_compile_options(transformer PRIVATE -Wall -Wextra -Wpedantic)
    endif()
else()
    message(WARNING "No source files found in source directory. Ensure you have added your .c files.")
endif()
