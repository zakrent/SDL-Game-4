//
// Created by zakrent on 7/21/17.
//

#ifndef GAME_4_POSITIONCOMPONENT_H
#define GAME_4_POSITIONCOMPONENT_H

#include "BaseComponent.h"

namespace Entity {
    class PositionComponent : public  BaseComponent{
    public:
        int x;
        int y;

        PositionComponent(int _x, int _y) : BaseComponent("Position"), x(_x), y(_y) {}
    };
}

#endif //GAME_4_POSITIONCOMPONENT_H
