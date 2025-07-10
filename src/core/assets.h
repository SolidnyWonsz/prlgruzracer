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
        
        // I seriously wonder if there's a better way to accomplish this

        Model &GetModel(const std::string &name);
        Image &GetImage(const std::string &name);
        Texture2D &GetTexture(const std::string &name);

    private:
        std::unordered_map<std::string, Model> models;
        std::unordered_map<std::string, Image> images;
        std::unordered_map<std::string, Texture2D> textures;
};