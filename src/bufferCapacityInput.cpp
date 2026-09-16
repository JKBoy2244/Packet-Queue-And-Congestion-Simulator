#include <iostream>
#include <limits>
#include <cstdlib>
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
              exit(EXIT_FAILURE);
          }

          std::cout << "Invalid input. Please enter a whole number.\n";
          continue;
     }

    /*
     std::string remainingInput {};
     std::getline(std::cin, remainingInput);

     bool onlyWhitespace { true };

     for (char character : remainingInput) {
       if (!std::isspace(static_cast<unsigned char>(character)))  {
         
         onlyWhitespace = false;
         break;
      }
    }

    if (!onlyWhitespace)  {
      
      std::cout << "Invalid input. Enter exactly one whole number.\n";
      continue;
    }
      
    */
      
      bool validRange {bufferCapacityNumber >= constants::minimumBufferCapacity && bufferCapacityNumber <= constants::maximumBufferCapacity};
      if (validRange) {

        cout << "That is an acceptable value!";
        return bufferCapacityNumber;
        
      } else {

        if (bufferAttempts == bufferChances) {

          cout << "Sorry your 3 chances ran out!";
          exit(EXIT_FAILURE);
        }
        cout << "Sorry that value is invalid, please try again!";
        continue;
      }
    }

    return 0;
  }
}
