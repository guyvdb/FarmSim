cmake_minimum_required(VERSION 3.1)

project(farm-sim)

set(EXECNAME "fsim")


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")




find_package(SFML COMPONENTS graphics window system REQUIRED)
find_package(ImGui-SFML REQUIRED)



add_executable(
    ${EXECNAME}
    src/main.cpp
    src/Game.cpp
    src/GameState.cpp
    src/MainMenuState.cpp
    src/GamePlayState.cpp
    src/simulation/Simulation.cpp
    src/simulation/Calendar.cpp
    src/agent/Agent.cpp
    src/story/Log.cpp 
    src/story/Director.cpp
)


target_include_directories(
    ${EXECNAME}
    PRIVATE
    src
)


target_link_libraries(
    ${EXECNAME}
    sfml-graphics
    sfml-window
    sfml-system
    ImGui-SFML::ImGui-SFML
)




