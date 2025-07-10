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

        template<typename T>
        T* CreateRenderable()
        {
            auto obj = std::make_unique<T>();
            T* ptr = obj.get();
            renderQueue.push_back(std::move(obj));
            return ptr;
        }

    private:
        std::vector<std::unique_ptr<IRenderable>> renderQueue;
};