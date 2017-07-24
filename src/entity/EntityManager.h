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
#include "Message.h"

namespace Entity{

    class EntityManager {
        std::vector< std::unique_ptr<Entity> > entities;
        std::vector< std::unique_ptr<BaseSystem> > systems;
        std::unordered_multimap<int64, std::unordered_map<std::string, Message> > messages; //1st key receiver ID (id 0 for broadcast), 2nd message subject (eg. DAMAGE, COLLISION)
        std::unordered_multimap<int64, std::unordered_map<std::string, Message> > newMessages;
    public:
        void addEntity(std::unique_ptr<Entity>);
        void createEntity(std::vector< std::unique_ptr<BaseComponent> > components){}; //Todo: implement
        void update(unsigned long long int updateNumber);

        EntityManager(SDL_Renderer *_renderer);
        ~EntityManager();
    };
}


#endif //GAME_4_ENTITYMANAGER_H
