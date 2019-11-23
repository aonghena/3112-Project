cmake_minimum_required(VERSION 3.5)

project(Todos LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Todos
        main.cpp
        ui/mainwindow.cpp
        ui/mainwindow.h
        ui/mainwindow.ui
        ui/taskwindow.h
        ui/taskwindow.cpp
        ui/taskwindow.ui
        UI/loginwindow.cpp
        UI/loginwindow.h
        UI/loginwindow.ui)

target_link_libraries(Todos PRIVATE Qt5::Widgets sqlite3)