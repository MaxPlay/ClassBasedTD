#pragma once

#include "PlayerControlType.h"
#include "PlayerClass.h"

namespace CBTD {
    namespace Game {
        namespace Session {
            struct PlayerTemplate
            {
                PlayerClass playerClass;
                PlayerControlType controlType;
                int playerID;
            };
        }
    }
}