#include <core/game.h>

int main()
{
    CGame *game = CGame::GetInstance();

    game->Start();
    game->Update();
    game->End();
}