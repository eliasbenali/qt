cmake_minimum_required(VERSION 3.1)
project(hello LANGUAGES CXX)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)

#find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5 COMPONENTS Core Gui Widgets CONFIG REQUIRED)

add_executable(hello1 hello1.cc)
target_link_libraries(hello1 Qt5::Core)

add_executable(hello2 WIN32 hello2.cc)
target_link_libraries(hello2 Qt5::Widgets)
