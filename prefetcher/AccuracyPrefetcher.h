#pragma once

#include "Prefetcher.h"

class AccuracyPrefetcher : public Prefetcher {
private:
    double predictionAccuracy;
    double prefetchDistance;
    double coverage;
    double timeliness;

public:
    AccuracyPrefetcher();
    AccuracyPrefetcher(double predictionAccuracy, double prefetchDistance, double coverage, double timeliness);

    double predict() const override;
};
