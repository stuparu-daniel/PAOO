//
// Created by drago on 12/15/2024.
//

#include "resource.h"

namespace paoo {
    Resource::Resource() {
      std::cout << "Resource acquired" << std::endl;
    }

    Resource::~Resource() {
      std::cout << "Resource released" << std::endl;
    }

    void Resource::use() {
      std::cout << "Using resource ..." << std::endl;
    }
}
