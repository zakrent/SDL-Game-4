//
// Created by zakrent on 7/31/17.
//

#include <vector>
#include "HealthSystem.h"
#include "../message/DamageMessage.h"
#include "../component/HealthComponent.h"

namespace Entity{

    void HealthSystem::updateEntity(Entity *entity, uint64 updateNumber) {
        HealthComponent* healthComponent = entity->getComponent<HealthComponent>("Health");
        if(!healthComponent)
            return;
        std::vector<DamageMessage> damageMessages = entityManager->getMessges<DamageMessage>(entity->getID(),"Damage");
        for(DamageMessage message : damageMessages){
            healthComponent->health -= message.damageValue;
        }
        if(healthComponent->health < 0)
            entity->destroy();
    }

    HealthSystem::HealthSystem(EntityManager *entityManager) :entityManager(entityManager){}

    void HealthSystem::update() {}
}