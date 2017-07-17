//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_STATE_H
#define GAME_4_STATE_H

#include <SDL_events.h>
#include <SDL_system.h>
#include "../Program.h"

namespace State {
    class BaseState {
    protected:
        Program* mainProgram;
    public:
        SDL_Renderer* renderer;
        virtual void update() = 0;
        virtual void handleEvent(SDL_Event& event) = 0;
        BaseState(SDL_Renderer* renderer, Program* mainProgram): renderer(renderer), mainProgram(mainProgram){}
    };
}

#endif //GAME_4_STATE_H
