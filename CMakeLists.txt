cmake_minimum_required(VERSION 3.10.0)
project(MMORPG VERSION 0.1.0 LANGUAGES C CXX)

set(sources
    main.cpp
    src/Character.cpp
    src/Warrior.cpp
    src/Mage.cpp
    src/Necromancer.cpp
    src/Array.cpp
)

add_executable(MMORPG ${sources})

target_include_directories(${PROJECT_NAME} PUBLIC include)

