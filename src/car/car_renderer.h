#pragma once

#include <renderer/renderable.h>
#include <raylib.h>
#include <string>

class CCarRenderer : public IRenderable
{
    public:
        CCarRenderer() = default;

        void SetModel(const std::string &model);
        void Update(const Vector3 &position, const Quaternion &rotation);
        void Draw() override;

    private:
        Model model;
        Vector3 position;
        Quaternion rotation;
};