#include <iostream>
#include <random>

#include "simulation.h"
using packets = int;

namespace simulation {

  void simulation(int arrivalCapacityNumber, int bufferCapacityNumber, int congestionThresholdNumber, int serviceCapacityNumber, int simulationDurationNumber, char option) {

    //packets bufferCapacity {1000};                       //maximum buffer capacity
    //packets currentQueue {850};                           //currently the number of packets inside the buffer
    //packets freeSpace {bufferCapacityNumber - currentQueue}       //number of spaces left for any external packets to join the buffer before it gets too full

    packets currentQueue { 0 };

    long long totalGenerated { 0 };                        //Each 4 variables are defined with the type long long essentially because totals get larger and eventually any of them would exceed 32-bit. 
    long long totalAccepted { 0 };
    long long totalDropped { 0 };
    long long totalTransmitted { 0 };
    long long totalQueueOccupancy { 0 };
    packets maximumQueue { 0 };                  //Maximum packets in the queue
    int congestedTicks { 0 };
    
    std::mt19937 generator { std::random_device{}() };
    std::uniform_int_distribution<int> arrivalDistribution { 0, arrivalCapacityNumber };

    for (int i {0}; i < simulationDurationNumber; ++i) {   //Indicates how many ticks it runs (how many simulation durations the program runs)
      
     // Temporary deterministic arrival count.
     // Later this will become a random value from 0 to arrivalCapacityNumber.
     packets arrivalsThisTick { arrivalDistribution(generator) };

     // Determine how many packet slots remain available.
     packets freeSpace { bufferCapacityNumber - currentQueue };

     packets acceptedPackets {};

     if (arrivalsThisTick <= freeSpace)  {
     
         acceptedPackets = arrivalsThisTick;
     } else  {
         acceptedPackets = freeSpace;
    }

     // Any packets that cannot fit are dropped.
     packets droppedPackets { arrivalsThisTick - acceptedPackets };

    // Only accepted packets enter the queue.
    currentQueue += acceptedPackets;

    packets transmittedPackets {};

    // The router cannot transmit more packets than actually exist.
    if (currentQueue <= serviceCapacityNumber) {
    
         transmittedPackets = currentQueue;
    } else  {
     
         transmittedPackets = serviceCapacityNumber;
    }

    currentQueue -= transmittedPackets;

    if (currentQueue > maximumQueue) {
    
      maximumQueue = currentQueue;
    }
      
    totalQueueOccupancy += currentQueue;

    if (currentQueue * 100 >= bufferCapacityNumber * congestionThresholdNumber)  {
      
       ++congestedTicks;
    }
      
    totalGenerated += arrivalsThisTick;
    totalAccepted += acceptedPackets;
    totalDropped += droppedPackets;
    totalTransmitted += transmittedPackets;

    if (option == 'y') {                      //This only shows if option == yes so user wants to display each tick summary, otherwise after doing all the tick simulation, the program prints the final results summary
      
      std::cout << "\n--- Simulation Tick << (i + 1) << " ---\n";
      std::cout << "Arrivals: " << arrivalsThisTick << '\n';
      std::cout << "Accepted: " << acceptedPackets << '\n';
      std::cout << "Dropped: " << droppedPackets << '\n';               //Results of each tick
      std::cout << "Transmitted: " << transmittedPackets << '\n';
      std::cout << "Queue remaining: " << currentQueue << '\n';
    }
  }

    double averageQueue { static_cast<double>(totalQueueOccupancy) / simulationDurationNumber};
    
    std::cout << "Total generated: " << totalGenerated << '\n';
    std::cout << "Total accepted: " << totalAccepted << '\n';
    std::cout << "Total dropped: " << totalDropped << '\n';
    std::cout << "Total transmitted: " << totalTransmitted << '\n';
    std::cout << "Packets remaining: " << currentQueue << '\n';
    std::cout << "Maximum queue: " << maximumQueue << '\n';
    std::cout << "Congested ticks: " << congestedTicks << '\n';
    std::cout << "Average queue: " << averageQueue << '\n';
    
    return;
  }
}
