cmake_minimum_required(VERSION 3.16)
project(EconomicForecasting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE LIB_SOURCES src/*.cpp)
list(REMOVE_ITEM LIB_SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)
add_library(EconomicForecasting STATIC ${LIB_SOURCES})

target_include_directories(EconomicForecasting PUBLIC include)

target_link_libraries(EconomicForecasting PUBLIC xgboost)

add_executable(ef_cli src/main.cpp)

target_link_libraries(ef_cli PRIVATE EconomicForecasting xgboost)

enable_testing()
find_package(GTest REQUIRED)
add_subdirectory(tests)
