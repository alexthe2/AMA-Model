#pragma once

class Prefetcher {
public:
    /// @brief Logic to predict if data will be needed in the future
    /// @return Returns 1 if prediction is true, 0 otherwise
    virtual double predict() const = 0;
};
