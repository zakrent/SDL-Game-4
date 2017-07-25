//
// Created by zakrent on 7/25/17.
//

#include "Random.h"
#include <cmath>

Random::Random()
        :distribution(0,9)
{

}

uint64 Random::getRandomNumber(int length) {
    uint64 result = 0;
    for (int i = 0; i < length; ++i) {
        result += distribution(generator)*pow(10,i);
    }
    return  result;
}

uint64 Random::getRandomID() {
    return getRandomNumber(19);
}