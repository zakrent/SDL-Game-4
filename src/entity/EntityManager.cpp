//
// Created by zakrent on 7/17/17.
//

#include <iostream>
#include "EntityManager.h"
#include "system/RenderSystem.h"
#include "components/PositionComponent.h"
#include "components/VisualComponent.h"

namespace Entity{

    EntityManager::EntityManager(SDL_Renderer *_renderer) {
        systems.push_back(std::unique_ptr<BaseSystem>(new RenderSystem(_renderer)));
        Entity* entity = new Entity();
        entity->addComponent(std::unique_ptr<BaseComponent>(new PositionComponent(1,0)));
        entity->addComponent(std::unique_ptr<BaseComponent>(new VisualComponent(SDL_Rect{0,0,24,24}) ));
        entities.push_back(std::unique_ptr<Entity>(entity));
    }

    EntityManager::~EntityManager() {}

    void EntityManager::update() {
        for(auto& systemPtr : systems){
            BaseSystem* system = systemPtr.get();
            system->update();
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