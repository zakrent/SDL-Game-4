//
// Created by zakrent on 7/24/17.
//

#ifndef GAME_4_AISYSTEM_H
#define GAME_4_AISYSTEM_H


#include <vector>
#include "BaseSystem.h"

namespace Entity {
    class AiSystem : public BaseSystem {
        std::vector< std::unique_ptr<Entity> >* entities;
        Entity* getEntityAtPos(int x, int y);
    public:
        void update();
        void updateEntity(Entity* entity, unsigned long long int updateNumber);

        AiSystem(std::vector< std::unique_ptr<Entity> >* _entities );
    };
}



#endif //GAME_4_AISYSTEM_H
