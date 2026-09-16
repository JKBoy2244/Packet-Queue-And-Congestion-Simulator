#include <cassert>  //necessary when asserting tests
#include <iostream>

#include "../constants.h"

static_assert(constants::minimumBufferCapacity >= 1);
static_assert(constants::maximumBufferCapacity <= 1000000);    
static_assert(constants:: minimumBufferCapacity < maximumBufferCapacity);           //This block enforces a strict limit of buffered capacity in terms of valid ranges

static_assert(constants::minimumServiceRate >= 1);
static_assert(constants::maximumServiceRate <= 50000);
static_assert(constants:: minimumServiceRate < maximumServiceRate);               //This block enforces a strict limit of service rates in terms of valid ranges

static_assert(constants::minimumArrivalRate >= 1);
static_assert(constants::maximumArrivalRate <= 50000);
static_assert(constants:: minimumArrivalRate < maximumArrivalRate);                     //This block enforces a strict limit of arrival rates in terms of valid ranges

static_assert(constants::minimumCongestionThresholdPercentage >= 1);
static_assert(constants::maximumCongestionThresholdPercentage <= 100);
static_assert(constants:: minimumCongestionThresholdPercentage < maximumCongestionThresholdPercentage);    /*This block enforces a strict limit of congestion threshold proportion in terms of 
                                                                                                             valid ranges*/

int main() {

  for (int a {1}; a <= 1000000; ++a) {

    assert(a >= constants::minimumBufferCapacity);
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

  for (int d {1}; d <= 100; ++d) {

    assert(d >= constants::minimumCongestionThresholdPercentage);
    assert(d <= constants::maximumCongestionThresholdPercentage);  
  }

  std:: cout << "All tests successfully passed!";
}
