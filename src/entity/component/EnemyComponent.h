//
// Created by zakrent on 7/21/17.
//

#ifndef GAME_4_ENEMYCOMPONENT_H
#define GAME_4_ENEMYCOMPONENT_H

#include "BaseComponent.h"

namespace Entity {
    class EnemyComponent  : public  BaseComponent{
    public:

        EnemyComponent() : BaseComponent("Enemy"){}
    };
}

#endif
