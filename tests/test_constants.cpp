#include <cassert>  //necessary when asserting tests
#include <iostream>

#include "../src/constants.h"

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

  for (int a {1}; a <= 1000000; ++a) {

    assert(a >= constants::minimumBufferCapacity);                                           //The loops tests are there essentially to make sure that every criteria is fully met
    assert(a <= constants::maximumBufferCapacity);
  }

  for (int b {1}; b <= 50000; ++b) {

    assert(b >= constants::minimumServiceRate);
    assert(b <= constants::maximumServiceRate);  
  }

  for (int c {1}; c <= 50000; ++c) {

    assert(c >= constants::minimumArrivalRate);
    assert(c <= constants::maximumArrivalRate);  
  }

  for (int d {1}; d <= 1000000; ++d) {

    assert(d >= constants::minimumSimulationDuration);
    assert(d <= constants::maximumSimulationDuration);  
  }

  for (int e {1}; e <= 100; ++e) {

    assert(e >= constants::minimumCongestionThresholdPercentage);
    assert(e <= constants::maximumCongestionThresholdPercentage);  
  }

  std::cout << "All tests successfully passed!";
}
