#include "NewGameMessage.h"

NewGameMessage::NewGameMessage(Map &mMap) : map(mMap){
    this->StartCell.x = map.getPlayerStart().x;
    this->StartCell.y = map.getPlayerStart().y;
}

std::string NewGameMessage::getMessage() {
    return "Начата новая игра. Размеры карты: "
              + std::to_string(map.getMapSizeByX()) + ' '
              + std::to_string(map.getMapSizeByY()) + ' '
              + "на координатах "
              + std::to_string(StartCell.x) + ' '
              + std::to_string(StartCell.y);
}
