cmake_minimum_required(VERSION 3.1)
project(Tedm)

include_directories(include)
include_directories(src)
include_directories(demos)
link_directories(${CMAKETEST_BINARY_DIR}/src)

set(SDL2_IMAGE_INCLUDE_DIR /usr/include/SDL2)
set(SDL2_IMAGE_LIBRARY /usr/lib/libSDL2_Image.so)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_image REQUIRED SDL2_image)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++1z -O2")

set(SOURCE_FILES
        src/objects/environment.hpp
        include/game.hpp
        src/Graphics.hpp
        include/Input.h
        include/KeyboardEvent.h
        src/objects/object.hpp
        src/objects/player.hpp
        src/objects/sprite.hpp
        include/state.hpp
        src/utils/Timer.hpp

        src/objects/environment.cpp
        old/game.cpp
        src/Graphics.cpp
        old/Input.cpp
        old/KeyboardEvent.cpp
        src/utils/Timer.cpp
        src/State.cpp src/State.h src/events/Event.cpp src/events/Event.h src/Context.cpp src/Context.h src/Game.cpp src/Game.h src/events/EventHandler.cpp src/events/EventHandler.h src/objects/Surface.cpp src/objects/Surface.h src/utils/Logger.cpp src/utils/Logger.h)

set(TARGETS demos/anakin_side.cpp demos/pong.cpp)

foreach (_src ${TARGETS})
    get_filename_component(EXEC_NAME ${_src} NAME_WE)

    add_executable(${EXEC_NAME} ${_src} ${SOURCE_FILES})
        MESSAGE(${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
    TARGET_LINK_LIBRARIES(${EXEC_NAME} ${SDL2_LIBRARIES} SDL2_image)
endforeach()