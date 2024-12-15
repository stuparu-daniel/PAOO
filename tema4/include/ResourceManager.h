//
// Created by drago on 12/15/2024.
//

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <memory>
#include <mutex>
#include "Resource.h"

namespace paoo
{
    class ResourceManager {

    public:
        // Constructor acquires resource
        ResourceManager();

        // Delete copy constructor and copy assignment
        ResourceManager(const ResourceManager&) = delete;
        ResourceManager& operator=(const ResourceManager&) = delete;

        // Move constructor
        ResourceManager(ResourceManager&& other) noexcept;

        // Move assignment
        ResourceManager& operator=(ResourceManager&& other) noexcept;

        // Thread-safe method to use the resource
        void useResource();

    private:
        std::unique_ptr<Resource> resource;  // Exclusive resource ownership
        mutable std::mutex mtx;              // Mutex for thread-safety
    };
}

#endif //RESOURCEMANAGER_H
