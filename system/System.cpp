#include "System.h"

System::System() {
    this->instance = SystemConfig::getInstance();

    this->localMemory = std::make_unique<LocalMemory>();
    this->remoteMemory = std::make_unique<RemoteMemory>();
    this->prefetcher = std::make_unique<AccuracyPrefetcher>();
}

System::System(std::unique_ptr<Memory> localMemory, std::unique_ptr<Memory> remoteMemory, std::unique_ptr<Prefetcher> prefetcher) {
    this->instance = SystemConfig::getInstance();

    this->localMemory = std::move(localMemory);
    this->remoteMemory = std::move(remoteMemory);
    this->prefetcher = std::move(prefetcher);
}

double System::averageAccessTime() const {
    double P = instance->getENV(CACHE_MISS_PROPABILITY);
    double H = prefetcher->predict(); // Hit rate after prefetching

    return P * (H * localMemory->accessTime() + (1-H) * remoteMemory->accessTime()) + (1-P) * localMemory->accessTime();
}
