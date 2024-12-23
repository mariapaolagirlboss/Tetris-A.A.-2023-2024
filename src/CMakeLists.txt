cmake_minimum_required(VERSION 3.26)
project(Tetris-A.A.-2023-2024)

set(CMAKE_CXX_STANDARD 17)
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIR} )
add_executable( Tetris-A.A.-2023-2024 main.cpp)
target_link_libraries(Tetris-A.A.-2023-2024 ${CURSES_LIBRARIES} )

#[[add_executable(Tetris-A.A.-2023-2024 main.cpp
        classica.hpp
        classifica.cpp)]]
