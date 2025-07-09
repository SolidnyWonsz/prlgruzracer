#include <renderer/renderer.h>

void CRenderer::Update()
{
    for (const auto &renderable : renderQueue)
    {
        renderable->Draw();
    }
}

template<typename T, typename... Args>
T* CRenderer::CreateRenderable(Args&&... args)
{
    auto obj = std::make_unique<T>(std::forward<Args>(args)...);
    T* ptr = obj.get();
    renderQueue.push_back(std::move(obj));
    return ptr;
}