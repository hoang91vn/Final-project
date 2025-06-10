cmake_minimum_required(VERSION 3.18)
project(EconomicForecasting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
find_package(CURL REQUIRED)

include_directories(include)

file(GLOB SOURCES src/*.cpp)
add_executable(EconomicForecasting ${SOURCES})

target_include_directories(EconomicForecasting PRIVATE include)
target_link_libraries(EconomicForecasting PRIVATE Python3::Python Python3::NumPy CURL::libcurl)

