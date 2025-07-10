#pragma once

#include <raylib.h>
#include <common/singleton.h>

class CCamera : public Singleton<CCamera>
{
    friend class Singleton<CCamera>;

    public:
        void Start();
        void BeginFrame();
        void EndFrame();

        Vector3 GetPosition() const
        {
            return camera.position;
        }

        void SetPosition(Vector3 position)
        {
            camera.position = position;
        }

        const Camera3D &GetCamera() const
        {
            return camera;
        }
    
    private:
        Camera3D camera;
};