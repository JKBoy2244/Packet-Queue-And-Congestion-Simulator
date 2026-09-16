#include <cassert>
#include <iostream>

#include "../src/metrics.h"

int main() {

  for (int i {0}; i <= 100; ++i) {
    for (int j {i}; j <= 100; ++j) {

      if (j == 0) {
        
         assert(metrics::calculateDropPercentage(i, j) == 0.0);          //This tests all possible outcomes
         assert(metrics::calculateCongestionPercentage(i, j) == 0.0);
         assert(metrics::calculateAverageOccupancyPercentage(i, j) == 0.0);
      } else {
      
        assert(metrics::calculateDropPercentage(i, j) == static_cast<double>(i) / j * 100.0);
        assert(metrics::calculateCongestionPercentage(i, j) == static_cast<double>(i) / j * 100.0);
        assert(metrics::calculateAverageOccupancyPercentage(i, j) == static_cast<double>(i) / j * 100.0);
      } 
    }
  }
}
