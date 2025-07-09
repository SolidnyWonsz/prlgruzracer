#include <renderer/renderer.h>

void CRenderer::Update()
{
    for (const auto &renderable : renderQueue)
    {
        renderable->Draw();
    }
}

template<typename T>
T* CRenderer::CreateRenderable()
{
    auto obj = std::make_unique<T>();
    T* ptr = obj.get();
    renderQueue.push_back(std::move(obj));
    return ptr;
}