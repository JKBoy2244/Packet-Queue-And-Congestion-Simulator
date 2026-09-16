#include "metrics.h"

namespace metrics  {
    double calculateDropPercentage(long long totalDropped, long long totalGenerated)  {

      
        if (totalGenerated == 0) {
            return 0.0;
        }

        return static_cast<double>(totalDropped) / totalGenerated * 100.0;
    }
}
