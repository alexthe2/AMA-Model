#include "LocalMemory.h"
#include "../config/SystemConfig.h"
#include "../config/Constants.h"

LocalMemory::LocalMemory() {
    instance = SystemConfig::getInstance();
}

double LocalMemory::accessTime() const {
    return instance->getENVorDefault(MEMORY_LATENCY_LOCAL_ACCESS, 0.5);
}
