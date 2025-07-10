#pragma once

#include <car/car.h>
#include <memory>

class CPlayer
{
    public:
        CPlayer(int id, bool isLocal);
        ~CPlayer();

        void Update();

        CCar controlledCar;

        // Multiplayer related
        // Will come in handy in the future
        int ID;
        bool isLocal;

        static std::unique_ptr<CPlayer> GetLocalPlayer();
};