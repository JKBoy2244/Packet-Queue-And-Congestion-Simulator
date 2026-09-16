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

    for (int i {0}; i < = simulationDurationNumber; ++i) {
      
     // Temporary deterministic arrival count.
     // Later this will become a random value from 0 to arrivalCapacityNumber.
     packets arrivalsThisTick { arrivalCapacityNumber };

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

    std::cout << "\n--- Simulation Tick ---\n";
    std::cout << "Arrivals: " << arrivalsThisTick << '\n';
    std::cout << "Accepted: " << acceptedPackets << '\n';
    std::cout << "Dropped: " << droppedPackets << '\n';
    std::cout << "Transmitted: " << transmittedPackets << '\n';
    std::cout << "Queue remaining: " << currentQueue << '\n';

  }
  return;
  }
}
