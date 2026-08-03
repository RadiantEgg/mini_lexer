cmake_minimum_required(VERSION 3.10)

project(mini_lexer)

message(STATUS "======================")
message(STATUS "Project: mini_lexer")
message(STATUS "CMake Version: ${CMAKE_VERSION}")
message(STATUS "======================")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build Type = ${CMAKE_BUILD_TYPE}")

# ---------------
# directories
# ---------------  

set(INC_DIR include)
set(SRC_DIR src)
set(APP_DIR app)
set(TESTS_DIR tests)


# ----------------
# library
# ----------------

set(LIB_SOURCES
    ${SRC_DIR}/token.c
    ${SRC_DIR}/lexer.c
)

add_library(mini_lexer_lib STATIC ${LIB_SOURCES})

target_include_directories(mini_lexer_lib
    PUBLIC
    ${INC_DIR}
)


# ----------------
# main executable
# ----------------

add_executable(mini_lexer
    ${APP_DIR}/main.c
)

target_link_libraries(mini_lexer
    PRIVATE
    mini_lexer_lib
)


# ----------------
# tests
# ----------------

add_executable(test_token
    ${TESTS_DIR}/test_token.c
)

target_link_libraries(test_token
    PRIVATE
    mini_lexer_lib
)