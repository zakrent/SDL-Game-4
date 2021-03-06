//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_BASESYSTEM_H
#define GAME_4_BASESYSTEM_H

#include "../Entity.h"

namespace Entity {
    class BaseSystem {
    public:
        virtual void update(){};
        virtual void updateEntity(Entity* entity, uint64 updateNumber){};

        BaseSystem(){}
    };
}

#endif //GAME_4_BASESYSTEM_H
