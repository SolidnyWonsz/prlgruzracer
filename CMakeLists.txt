cmake_minimum_required(VERSION 3.29)

project(prlgr VERSION 0.1)

set(SOURCES
    src/car/car_controller.cpp
    src/car/car_renderer.cpp
    src/car/car.cpp

    src/core/assets.cpp
    src/core/main.cpp
    src/core/game.cpp

    src/player/player_controller.cpp

    src/renderer/renderer.cpp

    src/world/world.cpp
)

add_executable(prlgruzracer ${SOURCES})

set_property(TARGET prlgruzracer PROPERTY CXX_STANDARD 20)

target_include_directories(prlgruzracer PRIVATE src)
target_link_libraries(prlgruzracer PRIVATE raylib m)