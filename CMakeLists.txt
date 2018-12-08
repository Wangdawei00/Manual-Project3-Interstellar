cmake_minimum_required(VERSION 3.12)
project(Manual-Project3-Interstellar-master)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})



set(CMAKE_EXE_LINKER_FLAGS "-framework OpenGL -framework GLUT")

add_executable(project3 Figure.cpp Shape.cpp Singleton.cpp vector.cpp Figure.h Shape.h Singleton.h vector.h)

target_link_libraries(project3 ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)