//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_ENTITYMANAGER_H
#define GAME_4_ENTITYMANAGER_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <SDL_render.h>
#include <string>
#include "../misc/types.h"
#include "Entity.h"
#include "system/BaseSystem.h"
#include "message/Message.h"
#include "../misc/Random.h"

namespace Entity{

    class EntityManager {
        Random randomGenerator;
        std::vector< std::unique_ptr<Entity> > entities;
        std::vector< std::unique_ptr<BaseSystem> > systems;
        std::unordered_multimap<uint64, std::unique_ptr<Message>> messages; //key receiver ID (id 0 for broadcast)
        std::unordered_multimap<uint64, std::unique_ptr<Message>> newMessages;
    public:
        void addEntity(std::unique_ptr<Entity>);
        void spawnPrefab(int prefabID, int x, int y);
        void createMessage(Message* message);
        void update(uint64 updateNumber);

        EntityManager(SDL_Renderer *_renderer);
        ~EntityManager();
    };
}


#endif //GAME_4_ENTITYMANAGER_H
