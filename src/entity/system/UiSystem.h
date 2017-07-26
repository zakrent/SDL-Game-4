//
// Created by zakrent on 7/26/17.
//

#ifndef GAME_4_UISYSTEM_H
#define GAME_4_UISYSTEM_H

#include "BaseSystem.h"
#include "../EntityManager.h"

namespace Entity {
    class UiSystem : public BaseSystem {
        EntityManager* entityManager;
        Entity* selectedEntity;
        bool hasBeenClicked;
        int lastClickX, lastClickY;
    public:
        void update();
        void updateEntity(Entity* entity, uint64 updateNumber);

        UiSystem(EntityManager* entityManager);
    };
}


#endif //GAME_4_UISYSTEM_H
