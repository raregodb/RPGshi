cmake_minimum_required(VERSION 3.25)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp
        Entities/Player.cpp Entities/Player.h
        System/Navigation/Navigation.cpp System/Navigation/Navigation.h
        System/Map/Cell.cpp System/Map/Cell.h
        System/Map/Map.cpp System/Map/Map.h
        System/Navigation/Position.cpp System/Navigation/Position.h
        System/Events/IEvent.h
        System/Events/Spikes/Spikes.cpp System/Events/Spikes/Spikes.h
        System/Events/HealPotion/HealPotion.cpp System/Events/HealPotion/HealPotion.h
        System/Events/Teleport/Teleport.cpp System/Events/Teleport/Teleport.h
        System/Map/MapGenerator/MapGenerator.cpp System/Map/MapGenerator/MapGenerator.h
        System/Game/Game.cpp System/Game/Game.h
        System/GameStates/MainMenu.cpp System/GameStates/MainMenu.h
        System/Game/Render/RenderGame.cpp System/Game/Render/RenderGame.h
        System/ControlSettings/InputReader/InputReader.cpp System/ControlSettings/InputReader/InputReader.h
        System/config/Input_Commands_Dir.h
        System/GameStates/SettingsMenu.cpp System/GameStates/SettingsMenu.h
        System/GameStates/IWindow.cpp System/GameStates/IWindow.h
        System/GameStates/GameState.h
        System/GameStates/PauseMenu.cpp System/GameStates/PauseMenu.h
        System/GameStates/GameOver.cpp System/GameStates/GameOver.h
        System/ControlSettings/InputList/InputList.cpp System/ControlSettings/InputList/InputList.h
        System/Events/Exit/Exit_event.cpp System/Events/Exit/Exit_event.h
        System/ControlSettings/CommandReader/ICommandReader.h System/ControlSettings/InputReader/I_InputReader.h System/ControlSettings/CommandReader/ConfigReader.cpp System/ControlSettings/CommandReader/ConfigReader.h)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries (lab1 ${CURSES_LIBRARIES})
endif()
