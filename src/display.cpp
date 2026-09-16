#include <iostream>

#include "display.h"

namespace display  {
    void displayTick(int tickNumber, int arrivalsThisTick, int acceptedPackets, int droppedPackets, int transmittedPackets, int currentQueue)  {
        std::cout << "\n--- Simulation Tick " << tickNumber << " ---\n";
        std::cout << "Arrivals: " << arrivalsThisTick << '\n';
        std::cout << "Accepted: " << acceptedPackets << '\n';
        std::cout << "Dropped: " << droppedPackets << '\n';
        std::cout << "Transmitted: " << transmittedPackets << '\n';
        std::cout << "Queue remaining: " << currentQueue << '\n';
    }

    void displaySummary(long long totalGenerated, long long totalAccepted, long long totalDropped, long long totalTransmitted, int currentQueue,
                        int maximumQueue, int congestedTicks, double averageQueue, double dropPercentage, double congestionPercentage, double averageOccupancyPercentage)  {
      
        std::cout << "\n--- Final Simulation Results ---\n";
        std::cout << "Total generated: " << totalGenerated << '\n';
        std::cout << "Total accepted: " << totalAccepted << '\n';
        std::cout << "Total dropped: " << totalDropped << '\n';
        std::cout << "Total transmitted: " << totalTransmitted << '\n';
        std::cout << "Packets remaining: " << currentQueue << '\n';
        std::cout << "Maximum queue: " << maximumQueue << '\n';
        std::cout << "Congested ticks: " << congestedTicks << '\n';
        std::cout << "Average queue: " << averageQueue << '\n';
        std::cout << "Drop percentage: " << dropPercentage << "%\n";
        std::cout << "Congestion percentage: " << congestionPercentage << "%\n";
        std::cout << "Average occupancy percentage: " << averageOccupancyPercentage << "%\n";
    }
}
