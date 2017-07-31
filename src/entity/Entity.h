//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_BASEENTITY_H
#define GAME_4_BASEENTITY_H

#include <unordered_map>
#include <memory>
#include "../misc/types.h"
#include "component/BaseComponent.h"

namespace Entity {
    class Entity {
        uint64 ID;
        std::unordered_map<std::string, std::unique_ptr<BaseComponent> > components;
    public:
        bool shouldBeDestroyed;
        void addComponent(std::unique_ptr<BaseComponent> component)
        {
            components[component.get()->name] = std::move(component);
        }
        template<typename T>
        T* getComponent(std::string name)
        {
            auto got = components.find(name);
            if (got == components.end())
                return nullptr;
            return static_cast<T*>(got->second.get());
        }
        void destroy(){shouldBeDestroyed = true;}
        uint64 getID(){ return  ID;}

        Entity(uint64 _ID):ID(_ID), shouldBeDestroyed(false){};
    };
}


#endif //GAME_4_BASEENTITY_H
