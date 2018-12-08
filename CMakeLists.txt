cmake_minimum_required(VERSION 3.12)
project(Manual-Project3-Interstellar)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})


set(CMAKE_EXE_LINKER_FLAGS "-framework OpenGL -framework GLUT")

add_executable(Manual-Project3-Interstellar Figure.cpp Shape.cpp vector.cpp main_sjl.cpp figures_sjl.cpp car_sjl.cpp)

target_link_libraries(Manual-Project3-Interstellar ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)

