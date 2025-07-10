#include <core/assets.h>
#include <iostream>

void CAssetManager::Update()
{
    
}

void CAssetManager::End()
{
    for (auto &[name, model] : models)
    {
        UnloadModel(model);
    }

    for (auto &[name, image] : images)
    {
        UnloadImage(image);
    }

    models.clear();
    images.clear();
}

Model &CAssetManager::GetModel(const std::string &name)
{
    if (!models.contains(name))
    {
        models[name] = LoadModel(name.c_str());
        if (!IsModelValid(models[name]))
        {
            std::cout << "Model invalid" << std::endl;
        }
    }

    return models[name];
}

Image &CAssetManager::GetImage(const std::string &name)
{
    if (!images.contains(name))
    {
        images[name] = LoadImage(name.c_str());
        if (!IsImageValid(images[name]))
        {
            std::cout << "Image invalid" << std::endl;
        }
    }

    return images[name];
}

Texture2D &CAssetManager::GetTexture(const std::string &name)
{
    if (!textures.contains(name))
    {
        textures[name] = LoadTexture(name.c_str());
    }

    return textures[name];
}