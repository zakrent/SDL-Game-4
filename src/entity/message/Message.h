//
// Created by zakrent on 7/17/17.
//

#ifndef GAME_4_MESSAGE_H
#define GAME_4_MESSAGE_H

namespace Entity {
    struct Message {
        std::string subject;
        uint64 receiverID;

        Message(std::string subject, uint64 receiverID):subject(subject), receiverID(receiverID){}
    };
}


#endif //GAME_4_MESSAGE_H
