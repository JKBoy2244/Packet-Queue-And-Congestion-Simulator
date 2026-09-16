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

    std::cout << "All simulation tests successfully passed!\n";

    return 0;
}
