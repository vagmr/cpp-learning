cmake_minimum_required(VERSION 3.5)
project(vaT VERSION 0.1 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#添加编译套件位置
set(CMAKE_PREFIX_PATH "H:\\qt-opensrc\\other\\6.2.4\\mingw_64") # Qt Kit Dir
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

 add_executable(vaT
     mainwindow.ui
     mainwindow.cpp
     main.cpp
     mainwindow.h
     secondWindow.h
     secondWindow.cpp
     signReceive.h
     signReceive.cpp
     mydialog.cpp
     mydialog.h
     mydialog.ui
     vaT.qrc
     logindialog.h
     logindialog.cpp
     logindialog.ui

 )

 target_link_libraries(vaT PRIVATE Qt6::Widgets)
target_include_directories(vaT PRIVATE "${CMAKE_BINARY_DIR}/vaT_autogen/include_Debug")

