#include <renderer/renderer.h>

void CRenderer::Update()
{
    for (const auto &renderable : renderQueue)
    {
        renderable->Draw();
    }
}