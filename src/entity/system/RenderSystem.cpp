//
// Created by zakrent on 7/21/17.
//

#include "RenderSystem.h"
#include "../component/VisualComponent.h"
#include "../component/PositionComponent.h"
#include "../component/UiComponent.h"

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

    void RenderSystem::renderTexture(SDL_Rect srcrect, Vector2D pixPosition, float scalingFactor = 0.75){
        SDL_Rect dstrect = {int(pixPosition.x), int(pixPosition.y), srcrect.w, srcrect.h};
        dstrect.x = ceil(dstrect.x/scalingFactor);
        dstrect.y = ceil(dstrect.y/scalingFactor);
        dstrect.w = ceil(dstrect.w/scalingFactor);
        dstrect.h = ceil(dstrect.h/scalingFactor);
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

    void RenderSystem::updateEntity(Entity *entity, uint64 updateNumber) {
        VisualComponent* visualComponent = entity->getComponent<VisualComponent>("Visual");
        PositionComponent* positionComponent = entity->getComponent<PositionComponent>("Position");
        UiComponent* uiComponent = entity->getComponent<UiComponent>("Ui");
        if(!visualComponent || !positionComponent)
            return;
        Vector2D pixPosition(positionComponent->x*visualComponent->srcrect.w, positionComponent->y*visualComponent->srcrect.h);
        if(!uiComponent) {
            renderTexture(visualComponent->srcrect, pixPosition);
            return;
        }
        renderTexture(visualComponent->srcrect, pixPosition, 1);
    }
}
