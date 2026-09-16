#include <iostream>
#include <limits>
#include "constants.h"

using namespace std;

constexpr int bufferChances = 3;
using packets = int;

namespace bufferCapacity {
  packets bufferCapacityInput() {

    packets bufferAttempts = 0;
    while (bufferAttempts < bufferChances) {

      cout << "What's the maximum number of packets you want that's waiting in the queue at once (minimum is 1 and maximum is 1000000?)";
      packets bufferCapacityNumber {};
      cin >> bufferCapacityNumber;
      bufferAttempts++;

      if (!std::cin) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          if (bufferAttempts == bufferChances) {
              std::cout << "Sorry, your 3 chances ran out!";
              return 0;
          }

          std::cout << "Invalid input. Please enter a whole number.\n";
          continue;
     }
      
      bool validRange {bufferCapacityNumber >= 1 && bufferCapacityNumber <= 1000000};
      if (!validRange) {

        if (bufferAttempts == bufferChances) {

          cout << "Sorry your 3 chances ran out!";
          exit_failure;
        }
        
        cout << "That is an acceptable value!";
        return bufferCapacityNumber;
        
      } else {

        if (bufferAttempts == bufferChances) {

          cout << "Sorry your 3 chances ran out!";
          exit_failure;
        }
        cout << "Sorry that value is invalid, please try again!";
        continue;
      }
    }
  }
}
