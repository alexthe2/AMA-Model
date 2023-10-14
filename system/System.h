#pragma once

#include <memory>

#include "../memory/header.h"
#include "../prefetcher/header.h"

#include "../config/header.h"

class System {
private:
    SystemConfig* instance;

    std::unique_ptr<Memory> localMemory;
    std::unique_ptr<Memory> remoteMemory;

    std::unique_ptr<Prefetcher> prefetcher;

public:
    System();
    System(std::unique_ptr<Memory> localMemory, std::unique_ptr<Memory> remoteMemory, std::unique_ptr<Prefetcher> prefetcher);

    double averageAccessTime() const;
};
