#pragma once

#include "Memory.h"
#include "../config/SystemConfig.h"

class RemoteMemory : public Memory {
    private:
        SystemConfig* instance;

    public:
        RemoteMemory();
        double accessTime() const override;
};
