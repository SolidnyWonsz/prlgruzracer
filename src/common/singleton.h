#pragma once

template <typename T>
class Singleton
{
    public:
        Singleton() = default;
        Singleton(const Singleton &other) = delete;

        static T* GetInstance()
        {
            static T _instance;
            return &_instance;
        }
};