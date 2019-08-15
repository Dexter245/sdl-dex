cmake_minimum_required(VERSION 3.7)
project(sdl_dex)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(sdl_dex
        include/Application.h
        include/Event.h
        include/EventListener.h
        include/Font.h
        include/Image.h
        include/ImageButton.h
        include/InputEventHandler.h
        include/Sixaxis.h
        include/Utils.h
        source/Application.cpp
        source/Event.cpp
        source/EventListener.cpp
        source/Font.cpp
        source/Image.cpp
        source/ImageButton.cpp
        source/InputEventHandler.cpp
        source/Sixaxis.cpp
        source/Utils.cpp
        Makefile )

add_custom_target(
        run-linux
        WORKING_DIRECTORY /home/dexter/Coding/switch/sdl-dex/
        COMMAND export DEVKITPRO=/opt/devkitpro && make run-linux
)

add_custom_target(
        run
        WORKING_DIRECTORY /home/dexter/Coding/switch/sdl-dex/
        COMMAND export DEVKITPRO=/opt/devkitpro && make run
)
