//
// Created by zakrent on 7/21/17.
//

#include "RenderSystem.h"
#include "../component/VisualComponent.h"
#include "../component/PositionComponent.h"
#include "../component/UiComponent.h"
#include "../component/HealthComponent.h"
#include "../component/SelectorComponent.h"

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
        HealthComponent* healthComponent = entity->getComponent<HealthComponent>("Health");
        SelectorComponent* selectorComponent = entity->getComponent<SelectorComponent>("Selector");
        if(!visualComponent || !positionComponent)
            return;
        Vector2D pixPosition(positionComponent->x*visualComponent->srcrect.w, positionComponent->y*visualComponent->srcrect.h);
        if(!uiComponent && !selectorComponent) {
            renderTexture(visualComponent->srcrect, pixPosition);
            if(healthComponent){
                renderHealthBar(pixPosition, (healthComponent->health/healthComponent->maxHealth)*100);
            }
            return;
        }
        renderTexture(visualComponent->srcrect, pixPosition, 1);
    }

    void RenderSystem::renderHealthBar(Vector2D position, float percentage) {
        SDL_Rect fillRect = {int(position.x/0.75+1),int(position.y/0.75+20), 30, 6};
        SDL_SetRenderDrawColor(renderer, 0x99, 0x89, 0x24, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);
        fillRect = {int(position.x/0.75+2),int(position.y/0.75+21), 28*(percentage/100), 4};
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
}
