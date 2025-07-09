#pragma once

#include <common/singleton.h>
#include <raylib.h>
#include <unordered_map>
#include <string>

class CAssetManager : public Singleton<CAssetManager>
{
    friend class Singleton<CAssetManager>;

    public:
        void Update();
        void End();
        
        Model &GetModel(const std::string &name);

    private:
        std::unordered_map<std::string, Model> models;
};