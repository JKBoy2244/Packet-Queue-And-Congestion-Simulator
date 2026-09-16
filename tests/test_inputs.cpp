#include <cassert>
#include <iostream>

#include "../src/constants.h"

#include "../src/arrivalCapacityInput.h"
#include "../src/bufferCapacityInput.h"
#include "../src/congestionThresholdInput.h"
#include "../src/detailedOutputChoose.h"
#include "../src/serviceCapacityInput.h"
#include "../src/simulationDurationInput.h"

static_assert(constants::minimumBufferCapacity >= 1);
static_assert(constants::maximumBufferCapacity <= 1000000);    
static_assert(constants::minimumBufferCapacity < constants::maximumBufferCapacity);           //This block enforces a strict limit of buffered capacity in terms of valid ranges

static_assert(constants::minimumServiceRate >= 1);
static_assert(constants::maximumServiceRate <= 50000);
static_assert(constants:: minimumServiceRate < constants::maximumServiceRate);               //This block enforces a strict limit of service rates in terms of valid ranges

static_assert(constants::minimumArrivalRate >= 1);
static_assert(constants::maximumArrivalRate <= 50000);
static_assert(constants:: minimumArrivalRate < constants::maximumArrivalRate);                     //This block enforces a strict limit of arrival rates in terms of valid ranges

static_assert(constants::minimumSimulationDuration >= 1);
static_assert(constants::maximumSimulationDuration <= 1000000);
static_assert(constants::minimumSimulationDuration < constants::maximumSimulationDuration);         //This block enforces a strict limit of simulation duration steps

static_assert(constants::minimumCongestionThresholdPercentage >= 1);
static_assert(constants::maximumCongestionThresholdPercentage <= 100);
static_assert(constants:: minimumCongestionThresholdPercentage < constants::maximumCongestionThresholdPercentage);    /*This block enforces a strict limit of congestion threshold proportion in terms of 
                                                                                                                          valid ranges*/

int main() {
  
    std::cout << "\nTesting buffer capacity input...\n";

    for (int bufferTest {0}; bufferTest < {1000}; ++bufferTest) {                                         //Each block here is each function input testing
      
      int buffer { bufferCapacity::bufferCapacityInput() };

      assert(buffer >= constants::minimumBufferCapacity);
      assert(buffer <= constants::maximumBufferCapacity);

    }

    std::cout << "\nTesting service capacity input...\n";
  
    for (int serviceTest {0}; serviceTest < {1000}; ++serviceTest) {
      int service { serviceCapacity::serviceCapacityInput() };

      assert(service >= constants::minimumServiceRate);
      assert(service <= constants::maximumServiceRate);

   }

    std::cout << "\nTesting arrival capacity input...\n";

    for (int arrivalTest {0}; arrivalTest < {1000}; ++arrivalTest) {
      int arrival { arrivalCapacity::arrivalCapacityInput() };

      assert(arrival >= constants::minimumArrivalRate);
      assert(arrival <= constants::maximumArrivalRate);

    }


    std::cout << "\nTesting simulation duration input...\n";

    for (int durationTest {0}; durationTest < {1000}; ++durationTest) {
      int duration { simulationDuration::simulationDurationInput() };

      assert(duration >= constants::minimumSimulationDuration);
      assert(duration <= constants::maximumSimulationDuration);

    }


    std::cout << "\nTesting congestion threshold input...\n";

    for (int congestionTest {0}; congestionTest < {1000}; ++congestionTest) {
      int congestion { congestionThreshold::congestionThresholdInput() };

      assert(congestion >= constants::minimumCongestionThresholdPercentage);
      assert(congestion <= constants::maximumCongestionThresholdPercentage);

    }


    std::cout << "\nTesting detailed output choice...\n";

    for (int congestionTest {0}; congestionTest < {1000}; ++congestionTest) {
      char detailed { detailedOutput::detailedOutputChoose() };

      assert(detailed == 'y' || detailed == 'n');

    }


    std::cout << "\nAll returned input values passed validation tests!\n";

    return 0;
}
