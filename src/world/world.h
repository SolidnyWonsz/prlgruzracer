#pragma once

#include <player/player_controller.h>
#include <memory>
#include <vector>
#include <common/singleton.h>

class CWorld : public Singleton<CWorld>
{
    friend class Singleton<CWorld>;

    public:
        void Start();
        void Update();
        void End();

        std::unique_ptr<CPlayer> &AddPlayer();

    private:
        std::vector<std::unique_ptr<CPlayer>> players;
};