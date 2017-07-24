//
// Created by zakrent on 7/24/17.
//

#include "AiSystem.h"
#include "../component/AiComponent.h"
#include "../component/PositionComponent.h"

namespace Entity {
    AiSystem::AiSystem(std::vector< std::unique_ptr<Entity> >* _entities )
    : entities(_entities){

    }

    void AiSystem::update() {
    }

    void AiSystem::updateEntity(Entity *entity, unsigned long long int updateNumber) {

        AiComponent* aiComponent = entity->getComponent<AiComponent>("Ai");
        PositionComponent* positionComponent = entity->getComponent<PositionComponent>("Position");
        if(!aiComponent || !positionComponent)
            return;
        switch(aiComponent->usedAiId){
            case 1:
                Entity* downEntity = getEntityAtPos(positionComponent->x,positionComponent->y+1);
                if(downEntity == nullptr && updateNumber%20 == 0)
                    positionComponent->y ++;
                break;
        }
    }

    Entity *AiSystem::getEntityAtPos(int x, int y) {
        for(auto& entityPtr : *entities) {
            PositionComponent* positionComponent = entityPtr.get()->getComponent<PositionComponent>("Position");
            if(positionComponent)
                if(positionComponent->x==x && positionComponent->y==y)
                    return entityPtr.get();
        }
        return nullptr;
    }
}
