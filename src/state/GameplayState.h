//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_GAMEPLAYSTATE_H
#define GAME_4_GAMEPLAYSTATE_H

#include <iostream>
#include "BaseState.h"
#include "../entity/EntityManager.h"

namespace State {
    class GameplayState : public BaseState {
        Entity::EntityManager entityManager;
        unsigned long long int updateNumber;
    public:
        void update();
        void handleEvent(SDL_Event& event);
        GameplayState(SDL_Renderer* renderer, Program* mainProgram)
                : entityManager(renderer), BaseState(renderer, mainProgram), updateNumber(0){}
    };
}


#endif //GAME_4_GAMEPLAYSTATE_H
