cmake_minimum_required(VERSION 3.20)
project(SimplexMethod)
set(CMAKE_CXX_STANDARD 17)

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "-O0 -g")
else ()
    set(CMAKE_CXX_FLAGS "-O3 -mwindows -DNDEBUG -s")
endif ()


file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} ".include/*.h")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "./src/*.cpp")
file(GLOB_RECURSE IMGUI2_SRC RELATIVE ${CMAKE_SOURCE_DIR} "./imgui-1.84.2/*.cpp")

set(SFML_DIR ./SFML-2.5.1-GCC//lib//cmake//SFML)

find_package(OpenGL REQUIRED)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

include_directories("./imgui-1.84.2")

add_subdirectory(tests)

include_directories(${SFML_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})


if (${CMAKE_BUILD_TYPE} MATCHES "Release")
    add_executable(SimplexMethod WIN32 main.cpp ${SOURCES} ${IMGUI2_SRC})
    set_property(TARGET SimplexMethod PROPERTY WIN32_EXECUTABLE true)
else ()
    add_executable(SimplexMethod main.cpp ${SOURCES} ${IMGUI2_SRC})
endif ()
target_link_libraries(SimplexMethod ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(SimplexMethod sfml-main sfml-network sfml-graphics sfml-window sfml-system)
