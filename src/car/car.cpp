#include <car/car.h>
#include <renderer/renderer.h>

CCar::CCar()
{
    renderer = CRenderer::GetInstance()->CreateRenderable<CCarRenderer>();
    renderer->SetModel("assets/model/car/car.glb");

    controller = CCarController((Vector3){0,0,0}, (Quaternion){0,0,0,0});
}

void CCar::Update()
{
    controller.Update();

    renderer->Update(controller.GetPosition(), controller.GetRotation());
}