//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_GAMEPLAYSTATE_H
#define GAME_4_GAMEPLAYSTATE_H

#include <event.h>
#include <iostream>
#include "BaseState.h"
#include "../entity/EntityManager.h"

namespace State {
    class GameplayState : public BaseState {
        Entity::EntityManager entityManager;
    public:
        void update();
        void handleEvent(SDL_Event& event);
        GameplayState(SDL_Renderer* renderer, Program* mainProgram): BaseState(renderer, mainProgram){}
    };
}


#endif //GAME_4_GAMEPLAYSTATE_H
