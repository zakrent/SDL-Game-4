//
// Created by zakrent on 7/31/17.
//

#ifndef GAME_4_HEALTHCOMPONENT_H
#define GAME_4_HEALTHCOMPONENT_H

#include "BaseComponent.h"

namespace Entity {
    class HealthComponent : public  BaseComponent{
    public:
        const float maxHealth;
        float health;
        HealthComponent(float health) : BaseComponent("Health"), health(health), maxHealth(health){}
    };
}

#endif //GAME_4_HEALTHCOMPONENT_H
