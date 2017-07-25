//
// Created by zakrent on 7/24/17.
//

#include "AiSystem.h"
#include "../component/AiComponent.h"
#include "../component/PositionComponent.h"
#include "../message/DamageMessage.h"

namespace Entity {
    AiSystem::AiSystem(std::vector< std::unique_ptr<Entity> >* _entities, EntityManager* entityManager)
    : entities(_entities), entityManager(entityManager){

    }

    void AiSystem::update() {
    }

    void AiSystem::updateEntity(Entity *entity, uint64 updateNumber) {

        AiComponent* aiComponent = entity->getComponent<AiComponent>("Ai");
        PositionComponent* positionComponent = entity->getComponent<PositionComponent>("Position");
        if(!aiComponent || !positionComponent)
            return;
        switch(aiComponent->usedAiId){
            case 1:
                Entity* downEntity = getEntityAtPos(positionComponent->x,positionComponent->y+1);
                if(downEntity == nullptr && updateNumber%20 == 0)
                    positionComponent->y ++;
                else if(updateNumber%20 == 0)
                    entityManager->createMessage(new DamageMessage(downEntity->getID(), 10));
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
