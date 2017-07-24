//
// Created by zakrent on 7/17/17.
//

#include <iostream>
#include "EntityManager.h"
#include "system/RenderSystem.h"
#include "component/PositionComponent.h"
#include "component/VisualComponent.h"
#include "system/AiSystem.h"
#include "component/AiComponent.h"

namespace Entity{

    EntityManager::EntityManager(SDL_Renderer *_renderer) {
        systems.push_back(std::unique_ptr<BaseSystem>(new RenderSystem(_renderer)));
        systems.push_back(std::unique_ptr<BaseSystem>(new AiSystem(&entities)));
        Entity* entity = new Entity();
        entity->addComponent(std::unique_ptr<BaseComponent>(new PositionComponent(1,0)));
        entity->addComponent(std::unique_ptr<BaseComponent>(new VisualComponent(SDL_Rect{0,0,24,24}) ));
        entity->addComponent(std::unique_ptr<BaseComponent>(new AiComponent(1)));
        entities.push_back(std::unique_ptr<Entity>(entity));
        entity = new Entity();
        entity->addComponent(std::unique_ptr<BaseComponent>(new PositionComponent(1,6)));
        entity->addComponent(std::unique_ptr<BaseComponent>(new VisualComponent(SDL_Rect{0,0,24,24}) ));
        entities.push_back(std::unique_ptr<Entity>(entity));
    }

    EntityManager::~EntityManager() {}

    void EntityManager::update(unsigned long long int updateNumber) {
        for(auto& systemPtr : systems){
            BaseSystem* system = systemPtr.get();
            system->update();
            for(auto& entityPtr : entities){
                Entity* entity = entityPtr.get();
                system->updateEntity(entity, updateNumber);
            }
        }
        messages = newMessages;
        newMessages.clear();
    }

    void EntityManager::addEntity(std::unique_ptr<Entity> entity) {
        entities.push_back(std::move(entity));
    }
}