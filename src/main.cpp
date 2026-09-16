#include <iostream>
#include <random>
#include <cstdlib>

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
#include "simulateOutputChoose.h"

using packets = int; 
using choice = char;

int main() {

  while (true) {
    
     packets bufferCapacityNumber = bufferCapacity::bufferCapacityInput();
     packets serviceCapacityNumber = serviceCapacity::serviceCapacityInput();
     packets arrivalCapacityNumber = arrivalCapacity::arrivalCapacityInput();
     packets simulationDurationNumber = simulationDuration::simulationDurationInput();
     packets congestionThresholdNumber = congestionThreshold::congestionThresholdInput();
     choice option = detailedOutput::detailedOutputChoose();
     simulation::simulation(arrivalCapacityNumber, bufferCapacityNumber, congestionThresholdNumber, serviceCapacityNumber, simulationDurationNumber, option);
     char simulateAgain = simulateOutput::simulateOutputChoose();

     if (simulateAgain == 'n') {

        cout << "We're sorry to see you go, come back soon though!\n";
        exit(0);
     }
  }
  return 0;
}
