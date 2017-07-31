//
// Created by zakrent on 7/31/17.
//

#ifndef GAME_4_ENTITYSELECTOR_H
#define GAME_4_ENTITYSELECTOR_H

#include "BaseComponent.h"

namespace Entity {
    class SelectorComponent  : public  BaseComponent{
    public:

        SelectorComponent() : BaseComponent("Selector"){}
    };
}

#endif //GAME_4_ENTITYSELECTOR_H
