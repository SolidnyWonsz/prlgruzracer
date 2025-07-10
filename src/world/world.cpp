#include <world/world.h>
#include <iostream>

void CWorld::Start()
{
    
}

void CWorld::Update()
{
    for (auto & [playerID, player] : players)
    {
        player.Update();
    }
}

void CWorld::End()
{
    players.clear();
}

CPlayer &CWorld::AddPlayer(int id, bool isLocal)
{
    auto [it, player] = players.emplace(id, CPlayer{id, isLocal});
    return it->second;
}