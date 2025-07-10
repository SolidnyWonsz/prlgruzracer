#include <core/game.h>
#include <core/assets.h>
#include <world/world.h>
#include <core/camera.h>
#include <renderer/renderer.h>
#include <raylib.h>
#include <iostream>

void CGame::Start()
{
    //SetTraceLogLevel(LOG_NONE);
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(1280, 720, "PRL Gruz Racer");
    SetWindowIcon(CAssetManager::GetInstance()->GetImage("assets/image/logo/logo_512x512.png"));
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    MaximizeWindow();
    InitAudioDevice();
    SetExitKey(0);

    //HideCursor();
    //DisableCursor();

    CWorld::GetInstance()->Start();
    CCamera::GetInstance()->Start();
    CPlayer &player = CWorld::GetInstance()->AddPlayer(0, true);
}

void CGame::Update()
{
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            if (IsCursorHidden())
            {
                ShowCursor();
                EnableCursor();
            }
            else
            {
                HideCursor();
                DisableCursor();
            }
        }

        if (IsCursorHidden())
        {
            UpdateCamera(&CCamera::GetInstance()->GetCamera(), CAMERA_FREE);
        }
        BeginFrame();
        CCamera::GetInstance()->BeginFrame();
        DrawGrid(10,10);

        CWorld::GetInstance()->Update();
        CRenderer::GetInstance()->Update();
        
        CCamera::GetInstance()->EndFrame();
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