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
        systems.push_back(std::unique_ptr<BaseSystem>(new AiSystem(&entities, this)));
        spawnPrefab(1,1,0);
        spawnPrefab(0,1,6);
    }

    EntityManager::~EntityManager() {}

    void EntityManager::update(uint64 updateNumber) {
        for(auto& systemPtr : systems){
            BaseSystem* system = systemPtr.get();
            system->update();
            for(auto& entityPtr : entities){
                Entity* entity = entityPtr.get();
                system->updateEntity(entity, updateNumber);
            }
        }
        std::swap(messages, newMessages);
        newMessages.clear();
    }

    void EntityManager::addEntity(std::unique_ptr<Entity> entity) {
        entities.push_back(std::move(entity));
    }

    void EntityManager::createMessage(Message *message) {
        newMessages.insert(std::unordered_multimap<uint64, std::unique_ptr<Message>>::value_type(message->receiverID, message));
    }

    void EntityManager::spawnPrefab(int prefabID, int x, int y) {
        Entity* entity = new Entity(randomGenerator.getRandomID());
        entity->addComponent(std::unique_ptr<BaseComponent>( new PositionComponent(x,y) ));
        switch(prefabID){
            case 0: //static entity
                entity->addComponent(std::unique_ptr<BaseComponent>(new VisualComponent(SDL_Rect{0,0,24,24}) ));
                break;
            case 1: //basic enemy
                entity->addComponent(std::unique_ptr<BaseComponent>(new VisualComponent(SDL_Rect{0,0,24,24}) ));
                entity->addComponent(std::unique_ptr<BaseComponent>(new AiComponent(1)));
                break;
            default:
                delete entity;
                return;
        }
        entities.push_back(std::unique_ptr<Entity>(entity));
    }
}