//
// Created by zakrent on 7/24/17.
//

#ifndef GAME_4_AICOMPONENT_H
#define GAME_4_AICOMPONENT_H

#include "BaseComponent.h"

namespace Entity {
    class AiComponent  : public  BaseComponent{
    public:
        int usedAiId;

        AiComponent(int _usedAiId) : BaseComponent("Ai"), usedAiId(_usedAiId){}
    };
}

#endif //GAME_4_AICOMPONENT_H
