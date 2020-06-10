cmake_minimum_required(VERSION 3.5)

project(geshba)

find_package(Curses REQUIRED)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -lncurses -lpanelw")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses -lpanelw")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB source_files "${source_dir}/*.cpp")

add_executable(${PROJECT_NAME} ${source_files})
