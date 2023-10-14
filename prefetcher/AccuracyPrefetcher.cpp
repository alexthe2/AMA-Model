#include "AccuracyPrefetcher.h"

#include <cstdlib>

#include "../config/header.h"

AccuracyPrefetcher::AccuracyPrefetcher() {
    SystemConfig* instance = SystemConfig::getInstance();

    this->predictionAccuracy = instance->getENVorDefault(PREFETCHER_ACCURACY, 0.9);
    this->prefetchDistance = instance->getENVorDefault(PREFETCHER_DISTANCE, 10);
    this->coverage = instance->getENVorDefault(PREFETCHER_COVERAGE, 0.8);
    this->timeliness = instance->getENVorDefault(PREFETCHER_TIMELINESS, 0.95);
}

AccuracyPrefetcher::AccuracyPrefetcher(double predictionAccuracy, double prefetchDistance, double coverage, double timeliness) {
    this->predictionAccuracy = predictionAccuracy;
    this->prefetchDistance = prefetchDistance;
    this->coverage = coverage;
    this->timeliness = timeliness;
}

double AccuracyPrefetcher::predict() const {
    return ((rand() / (double)RAND_MAX) < predictionAccuracy) ? 1 : 0;
}
