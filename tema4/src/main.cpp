//
// Created by drago on 12/15/2024.
//

#include "Resource.h"
#include "ResourceManager.h"
#include <thread>

void worker(paoo::ResourceManager& rm) {
    rm.useResource();
}

int main()
{
    paoo::ResourceManager rm1;

    // Simulate multiple threads using the resource manager
    std::thread t1(worker, std::ref(rm1));
    std::thread t2(worker, std::ref(rm1));

    t1.join();
    t2.join();

    std::cout << "Moving resource ..." << std::endl;
    paoo::ResourceManager rm2 = std::move(rm1);

    rm2.useResource();  // Safely use moved resource

    std::cout << "Moving resource ..." << std::endl;
    paoo::ResourceManager rm3(std::move(rm2));

    rm3.useResource();
    return 0;
}
