cmake_minimum_required(VERSION 3.15)

set(VCPKG_TARGET_TRIPLET "x86-windows-static")
set(CMAKE_TOOLCHAIN_FILE vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

project(test)

find_package(V8 CONFIG REQUIRED)

add_executable(test main.cpp)
target_link_libraries(test PRIVATE V8::V8)
