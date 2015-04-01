cmake_minimum_required(VERSION 2.8.9)
project(flackbot-qt)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5WebKit REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SRC
    src/main.cpp
    src/mainwindow.cpp
)

add_executable(flackbot-qt WIN32 ${SRC})
qt5_use_modules(flackbot-qt
    Widgets
    WebKit
)

install(TARGETS flackbot-qt
    RUNTIME DESTINATION bin
)
