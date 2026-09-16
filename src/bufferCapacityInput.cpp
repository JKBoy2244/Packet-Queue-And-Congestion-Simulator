#include <iostream>
#include "constants.h"
using namespace std;

constexpr final int bufferChances = 3;

namespace bufferCapacity {
  int bufferCapacityInput() {

    int bufferAttempts = 0;
    while (bufferAttempts < bufferChances) {

      cout << "What's the maximum number of packets you want that's waiting in the queue at once (minimum is 1 and maximum is 1000000?";
      string bufferCapacity {};
      cin >> bufferCapacity;
      bufferAttempts++;
      
      if (!std::cin) {
        if (bufferAttempts == bufferChances) {

          cout << "Sorry your 3 chances ran out!";
          exit_failure;
        }
        cout << "Sorry, you have to enter something to continue, please try again!";
        return;
      }

      int bufferCapacityNumber = static_cast<int>(bufferCapacity);
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
        cout << "Sorry that value is invalud, please try again!";
        return;
      }
    }
  }
}
