#include "NewGameMessage.h"

NewGameMessage::NewGameMessage(Map &mMap) : map(mMap){

}

Map &NewGameMessage::getMap() {
    return map;
}

Position NewGameMessage::getStartCell() {
    return StartCell;
}
std::string NewGameMessage::getMessage() {
    return "Начата новая игра. Размеры карты: "
              + std::to_string(map.getMapSizeByX()) + ' '
              + std::to_string(map.getMapSizeByY()) + ' '
              + "на координатах "
              + std::to_string(map.getPlayerStart().x) + ' '
              + std::to_string(map.getPlayerStart().y);
}
