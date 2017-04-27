cmake_minimum_required(VERSION 3.1)
project(Tedm)

include_directories(${CMAKETEST_SOURCE_DIR}/include)
include_directories(${CMAKETEST_SOURCE_DIR}/src)
include_directories(${CMAKETEST_SOURCE_DIR}/demos)
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
        include/environment.hpp
        include/Event.h
        include/game.hpp
        include/gamewithloopEXAMPLE.h
        include/graphics.hpp
        include/Input.h
        include/KeyboardEvent.h
        include/object.hpp
        include/player.hpp
        include/sprite.hpp
        include/state.hpp
        include/timer.hpp

        src/environment.cpp
        src/Event.cpp
        src/game.cpp
        src/gamewithloopEXAMPLE.cpp
        src/graphics.cpp
        src/Input.cpp
        src/KeyboardEvent.cpp
        src/timer.cpp
        )

set(TARGETS demos/anakin_side.cpp demos/pong.cpp)

foreach (_src ${TARGETS})
    get_filename_component(EXEC_NAME ${_src} NAME_WE)

    add_executable(${EXEC_NAME} ${_src} ${SOURCE_FILES})
    TARGET_LINK_LIBRARIES(${EXEC_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARY})
endforeach()