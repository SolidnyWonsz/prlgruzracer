#include <world/world.h>
#include <iostream>

void CWorld::Start()
{
    
}

void CWorld::Update()
{
    for (auto &player : players)
    {
        player->Update();
    }
}

void CWorld::End()
{
    players.clear();
}

std::unique_ptr<CPlayer> &CWorld::AddPlayer()
{
    return players.emplace_back(new CPlayer());
}