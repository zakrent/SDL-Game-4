//
// Created by zakrent on 7/25/17.
//

#ifndef GAME_4_MOUSEMESSAGE_H
#define GAME_4_MOUSEMESSAGE_H

#include "Message.h"
#include "../../misc/types.h"

namespace Entity{
    struct MouseClickMessage : public Message{
        int pixX;
        int pixY;

        MouseClickMessage(int x, int y)
                : Message("MouseClick", 0), pixX(x), pixY(y){}
    };
}

#endif //
