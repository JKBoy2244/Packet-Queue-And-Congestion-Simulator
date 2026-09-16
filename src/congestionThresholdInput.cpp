#include <iostream>
#include <limits>
#include <cstdlib>
#include "constants.h"

#include "serviceCapacityInput.h"

using namespace std;

constexpr int congestionChances = 3;               //Initialising chances to 3 as maximum
using packets = int;                      //Defining packets as an alias for type int

namespace congestionThreshold {
  packets congestionThresholdInput() {

    packets congestionAttempts = 0;
    while (congestionAttempts < congestionChances) {                                        //This continuously loops until the 3 attempts finished if and only if 3 attempts are invalid

      cout << "What percentage of the buffer when classifying the queue as congested do you want (minimum is 1 and maximum is 100?)";       
      packets congestionThresholdNumber {};
      cin >> congestionThresholdNumber;                                                     //This part prompts user to enter the buffer percentage
      congestionAttempts++;

      if (!std::cin) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                           //Warns if no input has been typed
          if (congestionAttempts == congestionChances) {
              std::cout << "Sorry, your 3 chances ran out!";
              exit(EXIT_FAILURE);
          }

          std::cout << "Invalid input. Please enter a whole number.\n";
          continue;
     }

     std::string remainingInput {};
     std::getline(std::cin, remainingInput);

     bool onlyWhitespace { true };

     for (char character : remainingInput) {
       if (!std::isspace(static_cast<unsigned char>(character)))  {                                   //Deals with whitespace issues and also potentially invalid characters after there's a valid number before it within the string
         
         onlyWhitespace = false;
         break;
      }
    }

    if (!onlyWhitespace)  {
      
      std::cout << "Invalid input. Enter exactly one whole number.\n";
      continue;
    }
      
      bool validRange {congestionThresholdNumber >= constants::minimumCongestionThresholdPercentage && congestionThresholdNumber <= constants::maximumCongestionThresholdPercentage};
      if (validRange) {

        cout << "That is an acceptable value!";                                                                  //Once there's a value, the program checks if the value is within the valid range or even if an integer is typed or not
        return congestionThresholdNumber;
        
      } else {

        if (congestionAttempts == congestionChances) {

          cout << "Sorry your 3 chances ran out!";
          exit(EXIT_FAILURE);                                                                //This only happens when there's a total of 3 invalid attempts causing the program to terminate unexpectedly/early
        }
        cout << "Sorry that value is invalid, please try again!";
        continue;
      }
    }

    return 0;
  }
}
