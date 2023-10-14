
#include <iostream>
#include <memory>

#include "system/System.h"

int main() {
    std::unique_ptr<System> system = std::make_unique<System>();

    std::cout << "Average access time: " << system->averageAccessTime() << std::endl;

    return 0;
}
