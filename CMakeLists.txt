cmake_minimum_required(VERSION 3.23)

project(YangVillageWeb)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

add_compile_options(-Wall -Wpedantic)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(include)

add_executable(yangvillage.wt
    src/main.cpp
    src/About.cpp
    src/Footer.cpp
    src/Header.cpp
    src/Home.cpp
    src/NavigationBar.cpp
    src/Portfolio.cpp
    src/Profile.cpp
    src/Section.cpp
    src/SocialLinks.cpp
)

target_link_libraries(yangvillage.wt wt wthttp)
