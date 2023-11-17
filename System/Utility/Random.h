#ifndef LAB1_RANDOM_H
#define LAB1_RANDOM_H

#include<cstdlib>
#include<ctime>
#include <random>

class Random {
public:
    static int getRandomNumber(int a, int b);
    static int getRandomGen(int a, int b);
};


#endif //LAB1_RANDOM_H
