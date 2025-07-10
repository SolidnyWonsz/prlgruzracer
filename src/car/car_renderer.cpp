#include <car/car_renderer.h>
#include <renderer/renderer.h>
#include <core/assets.h>
#include <iostream>

void CCarRenderer::SetModel(const std::string &model)
{
    this->model = CAssetManager::GetInstance()->GetModel(model.c_str());
}

void CCarRenderer::Update(const Vector3 &position, const Quaternion &rotation)
{
    this->position = position;
    this->rotation = rotation;
}

void CCarRenderer::Draw()
{
    std::cout << "dupa" << std::endl;
    DrawModel(model, position, 1, WHITE);
}