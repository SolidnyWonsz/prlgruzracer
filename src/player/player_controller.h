#pragma once

#include <car/car.h>

class CPlayer
{
    public:
        CPlayer();
        ~CPlayer();

        void Update();

        CCar controlledCar;
        int ID;
};