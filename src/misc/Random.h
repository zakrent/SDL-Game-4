//
// Created by zakrent on 7/25/17.
//

#ifndef GAME_4_RANDOM_H
#define GAME_4_RANDOM_H

#include "types.h"
#include <random>

class Random {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

public:
    uint64 getRandomNumber(int length);
    uint64 getRandomID();
    Random();
};


#endif //GAME_4_RANDOM_H
