//
// Created by zakrent on 7/25/17.
//

#ifndef GAME_4_DAMAGEMESSAGE_H
#define GAME_4_DAMAGEMESSAGE_H

#include "Message.h"
#include "../../misc/types.h"

namespace Entity{
    struct DamageMessage : public Message{
        int damageValue;

        DamageMessage(uint64 receiverID, int damageValue)
                : Message("Damage", receiverID), damageValue(damageValue){}
    };
}

#endif //GAME_4_DAMAGEMESSAGE_H
