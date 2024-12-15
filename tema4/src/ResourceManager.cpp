//
// Created by drago on 12/15/2024.
//

#include "ResourceManager.h"

namespace paoo
{
    ResourceManager::ResourceManager() :  resource(std::make_unique<Resource>())
    {
        std::cout << "New instance of Resource Manager created" << std::endl;
    }

    ResourceManager::ResourceManager(ResourceManager&& other) noexcept
    {
        std::lock_guard<std::mutex> lock(other.mtx);
        resource = std::move(other.resource);
        std::cout << "Resource moved" << std::endl;
    }
    ResourceManager& ResourceManager::operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            std::lock_guard<std::mutex> lock1(mtx);
            std::lock_guard<std::mutex> lock2(other.mtx);
            resource = std::move(other.resource);
            std::cout << "Resource moved (assignment).\n";
        }
        return *this;
    }

    void ResourceManager::useResource() {
        std::lock_guard<std::mutex> lock(mtx);
        if (resource)
        {
            resource->use();
        }
    }


}
