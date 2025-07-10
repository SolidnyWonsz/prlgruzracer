#include <core/camera.h>

void CCamera::Start()
{
    camera = { 0 };
    camera.position = (Vector3){0,0,0};
    camera.target = (Vector3){10,0,0};
    camera.up = (Vector3){0,1,0};
    camera.fovy = 70.0f;
    camera.projection = CAMERA_THIRD_PERSON;
}

void CCamera::BeginFrame()
{
    UpdateCamera(&camera, CAMERA_THIRD_PERSON);
    BeginMode3D(camera);
}

void CCamera::EndFrame()
{
    EndMode3D();
}