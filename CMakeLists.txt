cmake_minimum_required(VERSION 3.16)
project(OjasEditor LANGUAGES CXX)

set(SOURCES src/main.cpp)
set(INCLUDES src/includes)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GTKMM_LIBRARY_DIRS})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${GTKMM_LIBRARIES})
message(GTKMM_LIBRARY_DIRS=${GTKMM_LIBRARY_DIRS})
message(GTK_LIBRARIES=${GTKMM_LIBRARIES})
