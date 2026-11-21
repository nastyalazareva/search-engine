cmake_minimum_required(VERSION 3.14)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(SearchEngine LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
set(OPENXLSX_CREATE_DOCS OFF CACHE BOOL "OPENXLSX_CREATE_DOCS" FORCE)
set(OPENXLSX_BUILD_SAMPLES OFF CACHE BOOL "OPENXLSX_BUILD_SAMPLES" FORCE)
set(OPENXLSX_BUILD_TESTS OFF CACHE BOOL "OPENXLSX_BUILD_TESTS" FORCE)
FetchContent_Declare(OpenXLSX
    GIT_REPOSITORY https://github.com/troldal/OpenXLSX.git
    GIT_TAG v0.5.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(OpenXLSX)

add_library(search_lib src/excel_reader.cpp src/json_reader.cpp src/csv_reader.cpp)
target_include_directories(search_lib PUBLIC include)
target_link_libraries(search_lib PRIVATE OpenXLSX::OpenXLSX)
target_compile_options(search_lib PRIVATE -Wall -Wextra)
add_subdirectory(apps)