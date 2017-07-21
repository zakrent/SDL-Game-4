//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_BASECOMPONENT_H
#define GAME_4_BASECOMPONENT_H

#include <string>

namespace Entity {
    class BaseComponent{
    public:
        std::string name;

        BaseComponent(std::string name) : name(name) {}
    };
}
#endif //GAME_4_BASECOMPONENT_H
