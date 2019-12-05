cmake_minimum_required(VERSION 3.15)
project(3112_Project LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)
include_directories(UI)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(3112_Project
        UI/loginwindow.cpp
        UI/loginwindow.h
        UI/mainwindow.cpp
        UI/mainwindow.h
        UI/registerwindow.cpp
        UI/registerwindow.h
        UI/taskwindow.cpp
        UI/taskwindow.h
        Database.h
        main.cpp
        Task.h
        UrgentTask.h
        User.h)

target_link_libraries(3112_Project PRIVATE Qt5::Widgets sqlite3)

