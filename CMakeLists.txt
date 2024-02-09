cmake_minimum_required(VERSION 3.25)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp
        Entities/Player/Player.cpp Entities/Player/Player.h
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
        System/Events/Exit/Exit_event.cpp System/Events/Exit/Exit_event.h
        System/ControlSettings/CommandReader/ICommandReader.h
        System/ControlSettings/InputReader/I_InputReader.h
        System/ControlSettings/CommandReader/ConfigReader.cpp System/ControlSettings/CommandReader/ConfigReader.h
        System/Events/Event_Types.h
        System/Utility/Random.cpp System/Utility/Random.h
        System/Events/Shop/Shop.cpp System/Events/Shop/Shop.h
        System/GameStates/ShopMenu.cpp System/GameStates/ShopMenu.h
        Entities/Player/Items.h
        Entities/Player/Inventory.cpp Entities/Player/Inventory.h
        System/Events/Souls/Souls.cpp System/Events/Souls/Souls.h
        System/Game/Render/IRenderGame.h
        System/Logger/Messages/IMesage.h
        System/Logger/Messages/WinMessage.cpp System/Logger/Messages/WinMessage.h
        System/Logger/Messages/LoseMessage.cpp System/Logger/Messages/LoseMessage.h
        System/Logger/Messages/NewGameMessage.cpp System/Logger/Messages/NewGameMessage.h
        System/Logger/Log/Log.cpp System/Logger/Log/Log.h
        System/Logger/Messages/MoveMessage.cpp System/Logger/Messages/MoveMessage.h
        System/Logger/Log/ILogger.h
        System/Logger/Messages/NoMoveMessage.cpp System/Logger/Messages/NoMoveMessage.h
        System/Logger/Log/LogFile.cpp System/Logger/Log/LogFile.h
        System/Logger/Log/LogType.h
        System/Logger/Logger.cpp System/Logger/Logger.h
        System/Logger/Messages/ExitMessage.cpp System/Logger/Messages/ExitMessage.h
        System/GameStates/LogMenu.cpp System/GameStates/LogMenu.h
        Entities/Enemy/Enemy.cpp Entities/Enemy/Enemy.h
        Entities/Enemy/SoulHunter/SHNavigation.cpp Entities/Enemy/SoulHunter/SHNavigation.h Entities/Enemy/WanderingGhost/WGNavigation.cpp Entities/Enemy/WanderingGhost/WGNavigation.h Entities/Enemy/EnemyType.h Entities/Enemy/WanderingGhost/WGInteraction.cpp Entities/Enemy/WanderingGhost/WGInteraction.h Entities/Enemy/SoulHunter/SHInteraction.cpp Entities/Enemy/SoulHunter/SHInteraction.h System/Utility/A*/Pathfinder.cpp System/Utility/A*/Pathfinder.h)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries (lab1 ${CURSES_LIBRARIES})
endif()
