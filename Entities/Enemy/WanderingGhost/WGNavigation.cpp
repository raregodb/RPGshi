#include "WGNavigation.h"

void WGNavigation::navigate(Position& position) {
    int random_n = Random::getRandomNumber(1, 4);

    switch (random_n) {
        case 1:
            position.x += 1;
            std::cout<<"changed"<<std::endl;
            break;
        case 2:
            position.y += 1;
            std::cout<<"changed"<<std::endl;
            break;
        case 3:
            position.x -= 1;
            std::cout<<"changed"<<std::endl;
            break;
        case 4:
            position.y -= 1;
            std::cout<<"changed"<<std::endl;
            break;
        default:
            break;
    }
    std::cout<<"walking..."<<std::endl;
}