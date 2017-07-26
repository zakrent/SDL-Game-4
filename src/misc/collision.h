//
// Created by zakrent on 7/26/17.
//

#ifndef GAME_4_COLLISION_H
#define GAME_4_COLLISION_H

#include <SDL_rect.h>

namespace Collision{
    bool pointBoxCollision(int pX, int pY, SDL_Rect box){
        return pX > box.x && pX < box.x + box.w && pY > box.y && pY < box.y + box.h;
    }
}

#endif //GAME_4_COLLISION_H
