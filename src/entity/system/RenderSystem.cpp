//
// Created by zakrent on 7/21/17.
//

#include "RenderSystem.h"
#include "../component/VisualComponent.h"
#include "../component/PositionComponent.h"

namespace Entity {
    RenderSystem::RenderSystem(SDL_Renderer *_renderer)
    : renderer(_renderer){
        loadSpriteSheet("textures/spriteSheet.bmp");
    }

    RenderSystem::~RenderSystem() {
        if(spriteSheet != nullptr){
            SDL_DestroyTexture(spriteSheet);
        }
    }

    void RenderSystem::renderTexture(SDL_Rect srcrect, Vector2D pixPosition){
        SDL_Rect dstrect = {int(pixPosition.x), int(pixPosition.y), srcrect.w, srcrect.h};
        SDL_RenderCopyEx(renderer, spriteSheet, &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
    }

    void RenderSystem::loadSpriteSheet(char *filePath) {
        SDL_Surface *tempSurface = NULL;
        tempSurface = SDL_LoadBMP(filePath);
        spriteSheet = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        tempSurface = NULL;
    }

    void RenderSystem::update() {
        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }

    void RenderSystem::updateEntity(Entity *entity, unsigned long long int updateNumber) {
        VisualComponent* visualComponent = entity->getComponent<VisualComponent>("Visual");
        PositionComponent* positionComponent = entity->getComponent<PositionComponent>("Position");
        if(!visualComponent || !positionComponent)
            return;
        Vector2D pixPosition(positionComponent->x*visualComponent->srcrect.w, positionComponent->y*visualComponent->srcrect.h);
        renderTexture(visualComponent->srcrect, pixPosition);
    }
}
