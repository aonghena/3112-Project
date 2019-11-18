cmake_minimum_required(VERSION 3.15)
project(Todos)

set(CMAKE_CXX_STANDARD 14)

add_executable(Todos main.cpp User.h Task.h UrgentTask.h Database.h)

target_link_libraries(Todos sqlite3)