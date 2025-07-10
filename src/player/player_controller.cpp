#include <player/player_controller.h>

CPlayer::CPlayer() 
{
    ID = 0;
}

CPlayer::~CPlayer() {}

void CPlayer::Update()
{
    controlledCar.Update();
}