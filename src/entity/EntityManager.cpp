//
// Created by zakrent on 7/17/17.
//

#include <iostream>
#include "EntityManager.h"

namespace Entity{

    EntityManager::EntityManager() {
        systems.push_back(std::make_unique<BaseSystem>());
        entities.push_back(std::make_unique<Entity>());
    }

    EntityManager::~EntityManager() {}

    void EntityManager::update() {
        for(auto& systemPtr : systems){
            BaseSystem* system = systemPtr.get();
            for(auto& entityPtr : entities){
                Entity* entity = entityPtr.get();
                system->updateEntity(entity);
            }
        }
        messages = newMessages;
        newMessages.clear();
    }

    void EntityManager::addEntity(std::unique_ptr<Entity> entity) {
        entities.push_back(std::move(entity));
    }
}