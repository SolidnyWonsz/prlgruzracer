#pragma once

#include <player/player_controller.h>
#include <car/car.h>
#include <memory>
#include <unordered_map>
#include <common/singleton.h>

class CWorld : public Singleton<CWorld>
{
    friend class Singleton<CWorld>;

    public:
        void Start();
        void Update();
        void End();

        CPlayer &AddPlayer(int id, bool isLocal);

    private:
        std::unordered_map<int, CPlayer> players;
};