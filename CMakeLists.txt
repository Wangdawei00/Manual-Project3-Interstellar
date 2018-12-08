cmake_minimum_required(VERSION 3.12)
project(Manual_Project3_interstellar)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)

find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(Manual_Project3_interstellar
        vector.cpp
        vector.h
        Figure.cpp
        Shape.cpp
        Shape.h
        main.cpp
        )

target_link_libraries(Manual_Project3_interstellar ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

