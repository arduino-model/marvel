cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME biglcd)
project(${PROJECT_NAME})

set(${CMAKE_PROJECT_NAME}_SKETCH src/biglcd.cpp)

link_directories(${ARDUINO_SDK}/libraries)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)



#### Uncomment below additional settings as needed.
set(${CMAKE_PROJECT_NAME}_BOARD mega)
set(${CMAKE_PROJECT_NAME}_PORT COM4)
set(mega.build.mcu atmega2560)
set(mega.upload.protocol wiring)
set(mega.upload.speed 115200)

#add_library(LedControl lib/LedControl/src)
LINK_DIRECTORIES(D:\\Users\\john\\Documents\\Arduino\\libraries)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})
