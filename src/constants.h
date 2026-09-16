#ifndef CONSTANTS
#define CONSTANTS

namespace constants {

  inline constexpr int minimumBufferCapacity = 1;
  inline constexpr int maximumBufferCapacity = 1000000;  //The queue can hold up to a maximum of 1 million packets
  inline constexpr int minimumServiceRate = 1;  
  inline constexpr int maximumServiceRate = 50000;  //The router can process at most 50000 packets within one tick
  inline constexpr int minimumArrivalRate = 1;
  inline constexpr int maximumArrivalRate = 50000;  //The user can configure the random arrival generator at most 50000 (50k) packets per tick
  inline constexpr int minimumCongestionThresholdPercentage = 1;    //Minimum otherwise the congested queue would be empty essentially
  inline constexpr int maximumCongestionThresholdPercentage = 100;  //Maximum amount for the congested queue to be actually full
  inline constexpr int minimumSimulationDuration = 1;
  inline constexpr int maximumSimulationDuration = 1000000;
  
}

#endif
