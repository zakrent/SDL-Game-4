//
// Created by zakrent on 7/24/17.
//

#include "AiSystem.h"
#include "../component/AiComponent.h"
#include "../component/PositionComponent.h"
#include "../message/DamageMessage.h"
#include "../component/EnemyComponent.h"

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
            case 1: {//basic enemy ai
                Entity *downEntity = entityManager->getEntityAtPos(positionComponent->x, positionComponent->y + 1);
                if (downEntity == nullptr && updateNumber % 20 == 0)
                    positionComponent->y++;
                else if (updateNumber % 20 == 0) {
                    EnemyComponent *enemyComponent = downEntity->getComponent<EnemyComponent>("Enemy");
                    if (!enemyComponent)
                        entityManager->createMessage(new DamageMessage(downEntity->getID(), 10));
                }
                break;
            }
            case 2: {//bullet ai
                Entity *upEntity = entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 1);
                if(updateNumber % 10 != 0)
                    return;
                if(positionComponent->y < 0)
                    entity->destroy();
                positionComponent->y--;
                if (upEntity != nullptr) {
                    EnemyComponent *enemyComponent = upEntity->getComponent<EnemyComponent>("Enemy");
                    if (enemyComponent)
                        entityManager->createMessage(new DamageMessage(upEntity->getID(), 40));
                        entity->destroy();
                }
                break;
            }
            case 3: {//turrent ai
                if(updateNumber%40 != 0)
                    return;

                bool shouldShoot = ( //todo: replace it with something normal
                        (entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 1) !=nullptr &&
                        entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 1)->getComponent<EnemyComponent>("Enemy")!=nullptr)||
                        (entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 2) !=nullptr &&
                        entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 2)->getComponent<EnemyComponent>("Enemy")!=nullptr)||
                        (entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 3) !=nullptr &&
                         entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 3)->getComponent<EnemyComponent>("Enemy")!=nullptr)||
                        (entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 4) !=nullptr &&
                         entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 4)->getComponent<EnemyComponent>("Enemy")!=nullptr)||
                        (entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 5) !=nullptr &&
                         entityManager->getEntityAtPos(positionComponent->x, positionComponent->y - 5)->getComponent<EnemyComponent>("Enemy")!=nullptr)
                    );
                if(shouldShoot){
                    entityManager->spawnPrefab(31,positionComponent->x, positionComponent->y, true);
                }
                break;
            }
        }
    }
}
