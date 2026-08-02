cmake_minimum_required(VERSION 3.10)

project(mini_lexer)

message(STATUS "======================")
message(STATUS "Project: mini_lexer")
message(STATUS "CMake Version: ${CMAKE_VERSION}")
message(STATUS "======================")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

message(STATUS "C Standard: ${CMAKE_C_STANDARD}")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build Type = ${CMAKE_BUILD_TYPE}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug mode: ENABLE DEBUG LOG")
else()
    message(STATUS "Release mode: DISABLE DEBUG LOG")
endif()

set(INC_DIR include)
set(SRC_DIR src)

message(STATUS "Include Dir: ${INC_DIR}")
message(STATUS "Src Dir: ${SRC_DIR}")

set(SOURCES
    ${SRC_DIR}/main.c
    ${SRC_DIR}/token.c
    ${SRC_DIR}/lexer.c
)

message(STATUS "Source Dir:")
foreach(src ${SOURCES})
    message(STATUS " -${src}")
endforeach()

add_executable(mini_lexer ${SOURCES})
target_include_directories(mini_lexer PUBLIC ${INC_DIR})
