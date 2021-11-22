cmake_minimum_required(VERSION 3.20)
project(Tests)
set(CMAKE_CXX_STANDARD 17)

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "-O0 -g")
else()
    set(CMAKE_CXX_FLAGS "-O3 -mwindows -DNDEBUG -s")
endif()



file(GLOB_RECURSE HEADERS RELATIVE "${CMAKE_SOURCE_DIR}/tests" "../include/*.h")
file(GLOB_RECURSE SOURCES RELATIVE "${CMAKE_SOURCE_DIR}/tests" "../src/*.cpp")
file(GLOB_RECURSE IMGUI2_SRC RELATIVE "${CMAKE_SOURCE_DIR}/tests" "../imgui-1.84.2/*.cpp")

set(SFML_DIR ../SFML-2.5.1-GCC//lib//cmake//SFML)

find_package(OpenGL REQUIRED)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

include_directories("../imgui-1.84.2")

if(1)
    add_subdirectory(googletest-master)
    enable_testing()
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
endif()

include_directories(${SFML_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(Tests WIN32 test.cpp ../src/SimplexMethod.cpp ../include/SimplexMethod.h)

target_link_libraries(Tests ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(Tests gtest gtest_main)
target_link_libraries(Tests sfml-main sfml-network sfml-graphics sfml-window sfml-system)
