cmake_minimum_required(VERSION 3.10)
project(EldenTree)


add_executable(EldenTree main.cpp EldenTree/EldenTree.cpp )

target_include_directories(EldenTree
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/EldenTree
)


if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(EldenTree PRIVATE -Wall -Wextra -Wpedantic)
elseif (MSVC)
    target_compile_options(EldenTree PRIVATE /W4)
endif()