#pragma once

class IRenderable
{
    public:
        virtual void Draw() = 0;
        virtual ~IRenderable() = default;
};