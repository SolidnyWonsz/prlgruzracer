#pragma once

#include <common/singleton.h>

class CGame : public Singleton<CGame>
{
    friend class Singleton<CGame>;

    public:
        void Start();
        void Update();
        void End();

        void BeginFrame();
        void EndFrame();

    private:
        CGame() = default;
};