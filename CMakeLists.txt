cmake_minimum_required(VERSION 3.1)
project(Tedm)

include_directories(src)
include_directories(demos)
link_directories(${CMAKETEST_BINARY_DIR}/src)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(sdl2 REQUIRED)
find_package(SDL2_image REQUIRED)

#INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})
message(${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_INCLUDE_DIR})
include_directories("/usr/local/include/")
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++1z -O2")

set(SOURCE_FILES
        src/events/Event.cpp
        src/events/Event.h
        src/events/EventHandler.cpp
        src/events/EventHandler.h
        src/events/EventListener.cpp
        src/events/EventListener.h
        src/events/EventTrigger.cpp
        src/events/EventTrigger.h

        src/img/Texture.cpp
        src/img/Texture.h

        src/objects/object.h
        src/objects/player.h
        src/objects/sprite.h

        src/utils/Logger.cpp
        src/utils/Logger.h
        src/utils/Timer.cpp
        src/utils/Timer.h

        src/Context.cpp
        src/Context.h
        src/Game.cpp
        src/Game.h
        src/Graphics.cpp
        src/Graphics.h
        src/State.cpp
        src/State.h)

set(TARGETS demos/anakin_side.cpp demos/pong.cpp demos/part1.cpp demos/part2.cpp demos/part3.cpp)

foreach (_src ${TARGETS})
    get_filename_component(EXEC_NAME ${_src} NAME_WE)

    add_executable(${EXEC_NAME} ${SOURCE_FILES} ${_src})
    MESSAGE(${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

    set(TARGET_TMP ${EXEC_NAME} ${SDL2_LIBRARIES}${SDL2_IMAGE_LIBRARIES})
    string(STRIP "${TARGET_TMP}" TARGET_TMP)
    TARGET_LINK_LIBRARIES(${TARGET_TMP})
endforeach()
