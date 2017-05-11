cmake_minimum_required(VERSION 3.6)
project(Enigma)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp plugboard.h plugboard.cpp reflector.cpp reflector.h rotor.cpp rotor.h rotor_configs.h rotor_manager.cpp rotor_manager.h user_interface.cpp user_interface.h)
add_executable(Enigma ${SOURCE_FILES})