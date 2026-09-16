#include "metrics.h"

namespace metrics  {
    double calculateDropPercentage(long long totalDropped, long long totalGenerated)  {

      
        if (totalGenerated == 0) {
            return 0.0;
        }

        return static_cast<double>(totalDropped) / totalGenerated * 100.0;
    }

    double calculateCongestionPercentage(int congestedTicks, int simulationDurationNumber)  {
        
      if (simulationDurationNumber == 0)  {
          
        return 0.0;
     }

    return static_cast<double>(congestedTicks) / simulationDurationNumber* 100.0;
   }

   double calculateAverageOccupancyPercentage(double averageQueue, int bufferCapacityNumber)  {

       
    if (bufferCapacityNumber == 0)  {
        
        return 0.0;
    }

    return averageQueue / bufferCapacityNumber* 100.0;
  }
}
