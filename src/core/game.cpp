#include <core/game.h>
#include <core/assets.h>
#include <world/world.h>
#include <raylib.h>

void CGame::Start()
{
    SetTraceLogLevel(LOG_NONE);
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(1280, 720, "PRL Gruz Racer");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    MaximizeWindow();
    InitAudioDevice();
    SetExitKey(0);

    CWorld::GetInstance()->Start();
    CPlayer *player = CWorld::GetInstance()->AddPlayer().get(); 
}

void CGame::Update()
{
    while (!WindowShouldClose())
    {
        BeginFrame();

        CWorld::GetInstance()->Update();
        
        EndFrame();
    }
}

void CGame::End()
{
    CWorld::GetInstance()->End();
    CAssetManager::GetInstance()->End();

    CloseAudioDevice();
    CloseWindow();
}

void CGame::BeginFrame()
{
    ClearBackground(BLACK);
    BeginDrawing();
}

void CGame::EndFrame()
{
    EndDrawing();
}