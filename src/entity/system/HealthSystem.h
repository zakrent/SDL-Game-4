//
// Created by zakrent on 7/31/17.
//

#ifndef GAME_4_HEALTHSYSTEM_H
#define GAME_4_HEALTHSYSTEM_H

#include "BaseSystem.h"
#include "../EntityManager.h"

namespace Entity{
    class HealthSystem : public BaseSystem {
        EntityManager* entityManager;
    public:
        void update();
        void updateEntity(Entity* entity, uint64 updateNumber);

        HealthSystem(EntityManager* entityManager);
    };
}

#endif //GAME_4_HEALTHSYSTEM_H
