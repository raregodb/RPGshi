cmake_minimum_required(VERSION 3.25)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp Entities/Player.cpp Entities/Player.h System/Navigation/Navigation.cpp System/Navigation/Navigation.h System/Map/Cell.cpp System/Map/Cell.h System/Map/Map.cpp System/Map/Map.h System/Navigation/Position.cpp System/Navigation/Position.h System/Events/IEvent.h System/Events/Spikes/Spikes.cpp System/Events/Spikes/Spikes.h System/Events/HealPotion/HealPotion.cpp System/Events/HealPotion/HealPotion.h System/Events/Teleport/Teleport.cpp System/Events/Teleport/Teleport.h System/Map/MapGenerator/MapGenerator.cpp System/Map/MapGenerator/MapGenerator.h System/Game/Game.cpp System/Game/Game.h)
