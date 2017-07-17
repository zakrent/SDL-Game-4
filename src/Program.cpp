//
// Created by zakrent on 7/17/17.
//

#include "Program.h"
#include "SDL.h"
#include "state/GameplayState.h"

Program::Program() {
    int error = SDL_Init(SDL_INIT_EVERYTHING);
    if(error < 0)
        throw error;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    std::unique_ptr<State::BaseState> gameplayState(new State::GameplayState(renderer, this));
    stateStack.push(std::move(gameplayState));
}

Program::~Program() {
    SDL_Quit();
}

void Program::startMainLoop() {
    while(!stateStack.empty()){
        updateStartedAt = SDL_GetTicks();

        auto currentState = stateStack.top().get();
        currentState->update();

        SDL_Event event;
        while( SDL_PollEvent( &event) != 0 && !stateStack.empty()) {
            currentState->handleEvent(event);
        }

        if (!SDL_TICKS_PASSED(SDL_GetTicks() + 1, updateStartedAt + MIN_UPDATE_TIME)) {
            SDL_Delay((updateStartedAt + MIN_UPDATE_TIME) - SDL_GetTicks());
        }
    }
}


