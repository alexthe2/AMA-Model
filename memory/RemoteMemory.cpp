#include "RemoteMemory.h"
#include "../config/SystemConfig.h"
#include "../config/Constants.h"

RemoteMemory::RemoteMemory() {
    instance = SystemConfig::getInstance();
}

double RemoteMemory::accessTime() const {
    return instance->getENVorDefault(MEMORY_LATENCY_REMOTE_ACCESS, 0.5);
}
