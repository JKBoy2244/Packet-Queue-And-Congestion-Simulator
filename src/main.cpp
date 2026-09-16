#include <iostream>
#include <random>

#include "constants.h"
#include "bufferCapacityInput.h"
#include "serviceCapacityInput.h"
#include "arrivalCapacityInput.h"
#include "simulationDurationInput.h"
#include "congestionThresholdInput.h"
#include "simulation.h"
#include "metrics.h"
#include "display.h"
#include "detailedOutputChoose.h"

using packets = int; 
using select = char;

int main() {

  while (true) {
    
     packets bufferCapacityNumber = bufferCapacity::bufferCapacityInput();
     packets serviceCapacityNumber = serviceCapacity::serviceCapacityInput();
     packets arrivalCapacityNumber = arrivalCapacity::arrivalCapacityInput();
     packets simulationDurationNumber = simulationDuration::simulationDurationInput();
     packets congestionThresholdNumber = congestionThreshold::congestionThresholdInput();
     select option = detailedOutput::detailedOutputChoose();
     simulation::simulation(bufferCapacityNumber, serviceCapacityNumber, arrivalCapacityNumber, simulationDurationNumber, congestionThresholdNumber, option);
  }
  return 0;
}
