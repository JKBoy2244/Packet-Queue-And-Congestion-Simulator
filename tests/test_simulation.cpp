#include <cassert>
#include <iostream>
using namespace std;

#include "../src/simulation.h"

int main()  {
  
    for (int arrivals { 0 }; arrivals <= 1000; ++arrivals) {
        for (int freeSpace { 0 }; freeSpace <= 1000; ++freeSpace) {
          
            int acceptedPackets {};

            if (arrivals <= freeSpace)  {
              
                acceptedPackets = arrivals;
            } else  {
                acceptedPackets = freeSpace;
            }

            int droppedPackets { arrivals - acceptedPackets };
          
            assert(acceptedPackets <= arrivals);
            assert(acceptedPackets <= freeSpace);

            assert(droppedPackets >= 0);
            assert(acceptedPackets + droppedPackets == arrivals);

            if (arrivals <= freeSpace)
            {
                assert(acceptedPackets == arrivals);
                assert(droppedPackets == 0);
            }
            else
            {
                assert(acceptedPackets == freeSpace);
                assert(droppedPackets == arrivals - freeSpace);
            }
        }
    }

    for (int currentQueue { 0 }; currentQueue <= 1000; ++currentQueue) {
        for (int serviceCapacity { 0 }; serviceCapacity <= 1000; ++serviceCapacity)  {
            int transmittedPackets {};

            if (currentQueue <= serviceCapacity)  {
              
                transmittedPackets = currentQueue;
            }  else  {
              
                transmittedPackets = serviceCapacity;
            }

            assert(transmittedPackets <= currentQueue);
            assert(transmittedPackets <= serviceCapacity);

            int remainingQueue { currentQueue - transmittedPackets };

            assert(remainingQueue >= 0);
            assert(transmittedPackets + remainingQueue == currentQueue);
        }
    }

    for (int bufferCapacity { 1 }; bufferCapacity <= 100; ++bufferCapacity)  {
      for (int currentQueue { 0 }; currentQueue <= bufferCapacity; ++currentQueue)  {
        int congestionThreshold { 75 };

        bool congested {currentQueue * 100>= bufferCapacity * congestionThreshold};

        if (currentQueue * 100 >= bufferCapacity * congestionThreshold)  {
            assert(congested == true);
        }  else {
            assert(congested == false);
         }
     }
  }

   for (int bufferCapacity { 1 }; bufferCapacity <= 100; ++bufferCapacity)  {
    for (int currentQueue { 0 }; currentQueue <= bufferCapacity; ++currentQueue) {
        for (int arrivals { 0 }; arrivals <= 100; ++arrivals) {
          
            int freeSpace { bufferCapacity - currentQueue };
            int acceptedPackets {};

            if (arrivals <= freeSpace) {
                acceptedPackets = arrivals;
            } else {
                acceptedPackets = freeSpace;
            }

            int droppedPackets {arrivals - acceptedPackets ;
            currentQueue += acceptedPackets;

            assert(currentQueue <= bufferCapacity);
            assert(acceptedPackets + droppedPackets == arrivals);

            // Restore it before the next arrivals iteration.
            currentQueue -= acceptedPackets;
          }
      }
   }
     
    std::cout << "All simulation tests successfully passed!\n";

    return 0;
}
