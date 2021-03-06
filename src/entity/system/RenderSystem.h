//
// Created by zakrent on 7/21/17.
//

#ifndef GAME_4_RENDERSYSTEM_H
#define GAME_4_RENDERSYSTEM_H

#include "BaseSystem.h"
#include <SDL_render.h>
#include "../../misc/Vector2D.h"

namespace Entity {
    class RenderSystem : public BaseSystem {
        SDL_Texture* spriteSheet;
        SDL_Renderer* renderer;

        void loadSpriteSheet(char* filePath);
        void renderTexture(SDL_Rect srcrect, Vector2D position, float scalingFactor);
        void renderHealthBar(Vector2D position, float percentage);
    public:
        void update();
        void updateEntity(Entity* entity, uint64 updateNumber);

        RenderSystem(SDL_Renderer* _renderer);
        ~RenderSystem();
    };
}


#endif //GAME_4_RENDERSYSTEM_H
