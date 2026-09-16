#ifndef METRICS
#define METRICS

namespace metrics  {

    double calculateDropPercentage(long long totalDropped, long long totalGenerated);
    double calculateCongestionPercentage(int congestedTicks, int simulationDurationNumber);
    double calculateAverageOccupancyPercentage(double averageQueue, int bufferCapacityNumber);
}

#endif
