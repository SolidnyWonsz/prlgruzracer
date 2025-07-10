#include <player/player_controller.h>
#include <world/world.h>

CPlayer::CPlayer(int id, bool isLocal) 
{
    ID = id;
    this->isLocal = isLocal;
}

CPlayer::~CPlayer() {}

void CPlayer::Update()
{
    controlledCar.Update();
}