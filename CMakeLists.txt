cmake_minimum_required(VERSION 2.8.9)
project(flackbot-qt)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5WebKit REQUIRED)
find_package(Qt5WebKitWidgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SRC
    src/main.cpp
    src/mainwindow.cpp
)

qt5_wrap_ui(UI
    src/mainwindow.ui
)

add_executable(flackbot-qt WIN32 ${SRC} ${UI})
qt5_use_modules(flackbot-qt
    Widgets
    WebKit
    WebKitWidgets
)

install(TARGETS flackbot-qt
    RUNTIME DESTINATION bin
)
