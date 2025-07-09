#pragma once

#include <common/singleton.h>
#include <renderer/renderable.h>
#include <memory>
#include <vector>

class CRenderer : public Singleton<CRenderer>
{
    friend class Singleton<CRenderer>;

    public:
        void Start();
        void Update();

        template<typename T, typename... Args>
        T* CreateRenderable(Args&&... args);

    private:
        std::vector<std::unique_ptr<IRenderable>> renderQueue;
};