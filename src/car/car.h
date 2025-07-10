#pragma once

#include <car/car_controller.h>
#include <car/car_renderer.h>

class CCar
{
    public:
        CCar();
        void Update();

        CCarRenderer *renderer;
        CCarController controller;
};