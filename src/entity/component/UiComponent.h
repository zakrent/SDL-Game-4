//
// Created by zakrent on 7/26/17.
//

#ifndef GAME_4_UICOMPONENT_H
#define GAME_4_UICOMPONENT_H

#include "BaseComponent.h"

namespace Entity {
    class UiComponent : public  BaseComponent{
    public:
        UiComponent() : BaseComponent("Ui"){}
    };
}

#endif //GAME_4_UICOMPONENT_H
