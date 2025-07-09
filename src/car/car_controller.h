#pragma once

#include <raylib.h>
#include <vector>
#include <math.h>

class CCarController
{
    public:
        void Update();

        Vector3 GetPosition() const;
        Quaternion GetRotation() const;

    private:
        Vector3 position;
        Quaternion rotation;

        void ProcessInput();

    public:
        struct Engine
        {
            float idleRPM = 1000.0f;
            float maxRPM = 7000.0f;
            float currentRPM;

            float GetTorque(float throttle) const
            {
                float peakTorque = 121.0f;
                float peakRPM = 5000.0f;

                if (currentRPM < peakRPM)
                    return throttle * peakTorque * (currentRPM/peakRPM);
                else
                    return throttle * peakTorque * (1.0f - (currentRPM - peakRPM) / (maxRPM - peakRPM));
            }

            float GetPower(float throttle) const
            {
                const float RPMToRadPerSec = currentRPM * 2.0f * PI / 60.0f;
                return GetTorque(throttle) * RPMToRadPerSec;
            }
        };

        struct Transmission
        {
            int gear = 1;
            std::vector<float> gearRatio = { 2.5f, 1.8f, 1.3f, 1.0f, 0.8f };
            float finalDriveRatio = 3.5f;
        };

    private:
        float throttle;
        float brake;
        float clutch;
        float steer;
};