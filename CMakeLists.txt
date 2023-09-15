cmake_minimum_required(VERSION 3.20.0)

project(DBot)

set(CMAKE_TOOLCHAIN_FILE "E:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_PREFIX_PATH "E:/dev/vcpkg/installed/x64-windows/share")

find_package(dpp CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE dpp::dpp)
target_include_directories(${PROJECT_NAME} PRIVATE "E:/dev/vcpkg/installed/x64-windows/include")


