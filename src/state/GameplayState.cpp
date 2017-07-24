//
// Created by zakrent on 7/17/17.
//

#include "GameplayState.h"
namespace State {

    void GameplayState::update() {
        updateNumber++;
        entityManager.update(updateNumber);
    }

    void GameplayState::handleEvent(SDL_Event &event) {
        switch(event.type){
            case SDL_QUIT:
                mainProgram->stateStack.pop();
                break;
            default:
                break;
        }
    }
}