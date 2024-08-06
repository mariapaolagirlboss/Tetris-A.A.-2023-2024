find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(tetris-cpp main.cpp)
target_link_libraries(tetris-cpp ${CURSES_LIBRARIES})