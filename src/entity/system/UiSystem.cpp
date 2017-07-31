//
// Created by zakrent on 7/26/17.
//

#include <vector>
#include <iostream>
#include "../../Program.h"
#include "UiSystem.h"
#include "../message/MouseClickMessage.h"
#include "../component/UiComponent.h"
#include "../component/VisualComponent.h"
#include "../component/PositionComponent.h"
#include "../../misc/collision.h"
#include "../component/SelectorComponent.h"

namespace Entity {
    UiSystem::UiSystem(EntityManager *entityManager)
            :entityManager(entityManager), selectedEntity(nullptr), hasBeenClicked(false), lastClickX(0), lastClickY(0){}

    void UiSystem::update() {
        hasBeenClicked = false;
        std::vector<MouseClickMessage> mouseClickMessages = entityManager->getMessges<MouseClickMessage>(0,"MouseClick");
        if(mouseClickMessages.size()>0)
            if(mouseClickMessages.back().pixY<SCREEN_HEIGHT-24 && selectedEntity){
                entityManager->spawnPrefab(
                        selectedEntity->getComponent<UiComponent>("Ui")->representedPrefabId,
                        int(mouseClickMessages.back().pixX/(24/0.75)),
                        int(mouseClickMessages.back().pixY/(24/0.75))
                );
            }else{
                hasBeenClicked = true;
                lastClickX = mouseClickMessages.back().pixX;
                lastClickY = mouseClickMessages.back().pixY;
            }
    }

    void UiSystem::updateEntity(Entity *entity, uint64 updateNumber) {
        SelectorComponent* selectorComponent = entity->getComponent<SelectorComponent>("Selector");
        UiComponent* uiComponent = entity->getComponent<UiComponent>("Ui");
        if(selectorComponent && selectedEntity){
            PositionComponent* positionComponent = entity->getComponent<PositionComponent>("Position");
            PositionComponent* selectedPos = selectedEntity->getComponent<PositionComponent>("Position");
            positionComponent->x = selectedPos->x;
            positionComponent->y = selectedPos->y;
        }
        if(!uiComponent)
            return;
        if(!selectedEntity)
            selectedEntity = entity;
        VisualComponent* visualComponent = entity->getComponent<VisualComponent>("Visual");
        PositionComponent* positionComponent = entity->getComponent<PositionComponent>("Position");
        if(!visualComponent || !positionComponent)
            return;
        SDL_Rect collider = SDL_Rect{positionComponent->x*visualComponent->srcrect.w, positionComponent->y*visualComponent->srcrect.h,  visualComponent->srcrect.w, visualComponent->srcrect.h};
        if(Collision::pointBoxCollision(lastClickX, lastClickY, collider)&&hasBeenClicked){
            selectedEntity = entity;
        }
    }
}