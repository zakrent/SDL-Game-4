//
// Created by zakrent on 7/24/17.
//

#ifndef GAME_4_AISYSTEM_H
#define GAME_4_AISYSTEM_H


#include <vector>
#include "BaseSystem.h"
#include "../EntityManager.h"

namespace Entity {
    class AiSystem : public BaseSystem {
        EntityManager* entityManager;
        std::vector< std::unique_ptr<Entity> >* entities;
        Entity* getEntityAtPos(int x, int y);
    public:
        void update();
        void updateEntity(Entity* entity, uint64 updateNumber);

        AiSystem(std::vector< std::unique_ptr<Entity> >* _entities, EntityManager* entityManager);
    };
}



#endif //GAME_4_AISYSTEM_H
