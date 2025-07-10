#include <core/camera.h>
#include <player/player_controller.h>

void CCamera::Start()
{
    camera = { 0 };
    camera.position = (Vector3){10,5,0};
    camera.target = (Vector3){1,5,0};
    camera.up = (Vector3){0,1,0};
    camera.fovy = 70.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

void CCamera::BeginFrame()
{
    BeginMode3D(camera);
}

void CCamera::Update()
{
    
}

void CCamera::EndFrame()
{
    EndMode3D();
}