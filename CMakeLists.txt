cmake_minimum_required(VERSION 3.6)
project(GAME-4)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(GAME-4 ${SDL2_INCLUDE_DIRS})

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

file(GLOB_RECURSE SOURCE_FILES
        "src/*.cpp"
        "src/*.h"
        )

add_executable(GAME-4 ${SOURCE_FILES} ${SOURCE_FILES} src/entity/component/AiComponent.h src/entity/system/AiSystem.cpp src/entity/system/AiSystem.h src/misc/Random.cpp src/misc/Random.h src/entity/message/DamageMessage.h)
target_link_libraries(GAME-4 ${SDL2_LIBRARIES})
file(COPY textures/ DESTINATION textures/)