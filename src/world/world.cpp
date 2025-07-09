#include <world/world.h>

void CWorld::Start()
{

}

void CWorld::Update()
{
    for (const auto &player : players)
    {
        player.get()->Update();
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