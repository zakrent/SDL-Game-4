//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_PROGRAM_H
#define GAME_4_PROGRAM_H


#include <SDL_video.h>
#include <SDL_system.h>
#include <stack>
#include <memory>

namespace State{
    class BaseState;
}

const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 360;

class Program {
private:
    const int MIN_UPDATE_TIME = 20;
    int updateStartedAt;
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    std::stack< std::unique_ptr<State::BaseState> > stateStack;

    void startMainLoop();

    Program();
    ~Program();
};


#endif //GAME_4_PROGRAM_H
