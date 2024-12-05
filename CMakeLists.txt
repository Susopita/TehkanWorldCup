cmake_minimum_required(VERSION 3.29)
project(INIT)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(INIT 
    main.cpp
    ${SOURCES}
)

target_compile_options(INIT PRIVATE -Wall -Wextra -Wpedantic -Werror)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Banderas para depuración, como AddressSanitizer
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Si estás en modo Release, podrías agregar flags de optimización, por ejemplo:
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -O3 -DNDEBUG")
endif()
