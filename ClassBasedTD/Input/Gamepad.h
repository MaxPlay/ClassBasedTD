#pragma once
namespace CBTD
{
    struct GamePadState;

    class Gamepad
    {
        const GamePadState* GetGamePadState(unsigned char id);
    };
}