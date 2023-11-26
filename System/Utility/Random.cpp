#include "Random.h"

int Random::getRandomNumber(int a, int b) {
    std::random_device rd; //генерация сида
    std::mt19937 gen(rd()); //использование алгоритма Mersenne Twister на основе данного сида
    std::uniform_int_distribution<> dist(a, b); //генерация рандомных значений на замкнутом интервале

    int random_n = dist(gen);
    return random_n;
}

int Random::getRandomGen(int a, int b) {
    std::random_device rd; //генерация сида
    std::mt19937 gen(rd()); //использование алгоритма Mersenne Twister на основе данного сида
    std::uniform_int_distribution<> dist(a, b); //генерация рандомных значений на замкнутом интервале
    return dist(gen);
}
