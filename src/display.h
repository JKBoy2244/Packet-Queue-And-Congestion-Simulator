#ifndef DISPLAY_H
#define DISPLAY_H

namespace display {

   void displayTick(int tickNumber, int arrivalsThisTick, int acceptedPackets, int droppedPackets, int transmittedPackets, int currentQueue);
   void displaySummary(long long totalGenerated, long long totalAccepted, long long totalDropped, long long totalTransmitted, int currentQueue,
                        int maximumQueue, int congestedTicks, double averageQueue, double dropPercentage, double congestionPercentage, double averageOccupancyPercentage);
}

#endif
