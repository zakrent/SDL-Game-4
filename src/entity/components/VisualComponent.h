//
// Created by zakrent on 7/21/17.
//

#ifndef GAME_4_VISUALCOMPONENT_H
#define GAME_4_VISUALCOMPONENT_H

#include "BaseComponent.h"

namespace Entity {
    class VisualComponent : public  BaseComponent{
    public:
        SDL_Rect srcrect;

        VisualComponent(SDL_Rect _srcrect) : srcrect(_srcrect), BaseComponent("Visual") {}
    };
}

#endif //GAME_4_VISUALCOMPONENT_H
