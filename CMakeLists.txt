cmake_minimum_required(VERSION 3.12)
project(Manual-Project3-Interstellar)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLUT_INCLUDE_DIR})


#set(CMAKE_EXE_LINKER_FLAGS "-framework OpenGL -framework GLUT")

add_executable(Manual-Project3-Interstellar Figure.cpp Shape.cpp vector.cpp main.cpp slot.cpp ParkingLot.cpp)

target_link_libraries(Manual-Project3-Interstellar ${GLUT_LIBRARY} ${OPENGL_LIBRARY})

#cmake_minimum_required(VERSION 3.12)
#project(test)
#
#set(CMAKE_CXX_STANDARD 17)
#find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
#include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

#add_executable(test main.cpp figure.cpp figure.h home.cpp home.h)
#target_link_libraries(test ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

