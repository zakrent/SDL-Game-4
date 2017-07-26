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
        std::vector< std::unique_ptr<Message> > messages; //key receiver ID (id 0 for broadcast)
        std::vector< std::unique_ptr<Message> > newMessages;
    public:
        void addEntity(std::unique_ptr<Entity>);
        void spawnPrefab(int prefabID, int x, int y);
        void createMessage(Message* message);
        void update(uint64 updateNumber);

        template <typename T>
        std::vector<T> getMessges(uint64 receiverID, std::string subject) {
            std::vector<T> result;
            for (auto& messagePtr : messages) {
                Message* message = messagePtr.get();
                if (message->subject == subject && message->receiverID == receiverID)
                    result.push_back(*static_cast<T*>(message));
                return result;
            }
        }

        EntityManager(SDL_Renderer *_renderer);
        ~EntityManager();
    };
}


#endif //GAME_4_ENTITYMANAGER_H
