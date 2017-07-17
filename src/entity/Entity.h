//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_BASEENTITY_H
#define GAME_4_BASEENTITY_H

#include <unordered_map>
#include <memory>
#include "../misc/types.h"
#include "components/BaseComponent.h"

namespace Entity {
    class Entity {
        //int64 int ID;
        bool shouldBeDestroyed;
        std::unordered_map<std::string, std::unique_ptr<BaseComponent> > components;
    public:
        void addComponent(std::unique_ptr<BaseComponent> componentPtr){
            BaseComponent* component = componentPtr.get();
            components[component->name] = std::move(componentPtr);
        };
        template<typename T>
        T* getComponent(std::string name)
        {
            auto got = components.find(name);
            if (got == components.end())
                return nullptr;
            BaseComponent* component = got->second.get();
            return dynamic_cast<T*>(component);
        }
        void destroy(){shouldBeDestroyed = true;};

        Entity(){};
    };
}


#endif //GAME_4_BASEENTITY_H
