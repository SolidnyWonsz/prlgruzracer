#include <car/car_controller.h>

CCarController::CCarController(Vector3 position, Quaternion rotation)
{
    this->position = position;
    this->rotation = rotation;
}

void CCarController::Update()
{

}

void CCarController::ProcessInput()
{
    if (IsKeyDown(KEY_W)) throttle = 1.0f;
    else if (IsKeyDown(KEY_S)) brake = 1.0f;
}

Vector3 CCarController::GetPosition() const
{
    return position;
}

Quaternion CCarController::GetRotation() const
{
    return rotation;
}