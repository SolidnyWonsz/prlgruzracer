#include <core/assets.h>

void CAssetManager::Update()
{
    
}

void CAssetManager::End()
{
    for (auto &[name, model] : models)
    {
        UnloadModel(model);
    }

    models.clear();
}

Model &CAssetManager::GetModel(const std::string &name)
{
    if (!models.contains(name))
    {
        models[name] = LoadModel(name.c_str());
    }

    return models[name];
}