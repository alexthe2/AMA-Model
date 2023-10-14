#pragma once

#include "Memory.h"
#include "../config/SystemConfig.h"

class LocalMemory : public Memory {
    private:
        SystemConfig* instance;

    public:
        LocalMemory();
        double accessTime() const override;
};
