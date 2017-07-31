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
#include "system/UiSystem.h"
#include "component/UiComponent.h"
#include "system/HealthSystem.h"
#include "component/HealthComponent.h"
#include "component/EnemyComponent.h"

namespace Entity{

    EntityManager::EntityManager(SDL_Renderer *_renderer) {
        systems.push_back(std::unique_ptr<BaseSystem>(new RenderSystem(_renderer)));
        systems.push_back(std::unique_ptr<BaseSystem>(new AiSystem(&entities, this)));
        systems.push_back(std::unique_ptr<BaseSystem>(new UiSystem(this)));
        systems.push_back(std::unique_ptr<BaseSystem>(new HealthSystem(this)));
        spawnPrefab(10,0,14);
        spawnPrefab(11,1,14);
    }

    EntityManager::~EntityManager() {}

    void EntityManager::update(uint64 updateNumber) {
        for(auto& systemPtr : systems){
            BaseSystem* system = systemPtr.get();
            system->update();
            for(int i = 0; i < entities.size(); i++){
                auto& entityPtr = entities[i];
                Entity* entity = entityPtr.get();
                if(entity == nullptr)
                    continue;
                system->updateEntity(entity, updateNumber);
                if(entity->shouldBeDestroyed) {
                    entityPtr.reset();
                    entities.erase(entities.begin()+i);
                }
            }
        }
        std::swap(messages, newMessages);
        newMessages.clear();
    }

    void EntityManager::addEntity(std::unique_ptr<Entity> entity) {
        entities.push_back(std::move(entity));
    }

    void EntityManager::createMessage(Message *message) {
        newMessages.push_back(std::unique_ptr<Message>(message));
    }

    void EntityManager::spawnPrefab(int prefabID, int x, int y) {
        if(getEntityAtPos(x,y))
            return;
        Entity* entity = new Entity(randomGenerator.getRandomID());
        entity->addComponent(std::unique_ptr<BaseComponent>( new PositionComponent(x,y) ));
        switch(prefabID){
            case 0: //static entity
                entity->addComponent(std::unique_ptr<BaseComponent>(new HealthComponent(100)));
                entity->addComponent(std::unique_ptr<BaseComponent>(new VisualComponent(SDL_Rect{0,0,24,24}) ));
                break;
            case 1: //basic enemy
                entity->addComponent(std::unique_ptr<BaseComponent>(new HealthComponent(100)));
                entity->addComponent(std::unique_ptr<BaseComponent>(new VisualComponent(SDL_Rect{24,0,24,24}) ));
                entity->addComponent(std::unique_ptr<BaseComponent>(new AiComponent(1)));
                entity->addComponent(std::unique_ptr<BaseComponent>(new EnemyComponent()));
                break;
            case 10: //ui -static entity spawn
                entity->addComponent(std::unique_ptr<BaseComponent>(new VisualComponent(SDL_Rect{0,0,24,24}) ));
                entity->addComponent(std::unique_ptr<BaseComponent>(new UiComponent(0)));
                break;
            case 11: //ui-basic enemy spawn
                entity->addComponent(std::unique_ptr<BaseComponent>(new VisualComponent(SDL_Rect{24,0,24,24}) ));
                entity->addComponent(std::unique_ptr<BaseComponent>(new UiComponent(1)));
                break;
            default:
                delete entity;
                return;
        }
        entities.push_back(std::unique_ptr<Entity>(entity));
    }

    Entity *EntityManager::getEntityAtPos(int x, int y) {
        for(auto& entityPtr : entities) {
            PositionComponent* positionComponent = entityPtr.get()->getComponent<PositionComponent>("Position");
            if(positionComponent)
                if(positionComponent->x==x && positionComponent->y==y)
                    return entityPtr.get();
        }
        return nullptr;
    }
}