#include <iostream>
#include <limits>
#include <cstdlib>

#include "simulateAgain.h"
using namespace std;

constexpr int simulateChances = 3;               //Initialising chances to 3 as maximum
using yesOrNo = char;                      //Defining yesOrNo as an alias for type char
using chances = int;                             //Defining chances as an alias for type int

namespace simulateOutput {

  yesOrNo simulateOutputChoose() {

     chances simulateAttempts = 0;
     while (simulateAttempts < simulateChances) {

         cout << "Do you want to simulate packets again or not (please only type y or n and all lower case?)";
         yesOrNo simulateOption {};
         cin >> simulateOption;
         simulateAttempts++;

         if (!std::cin) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                           //Warns if no input has been typed
           
          if (simulateAttempts == simulateChances) {
              std::cout << "Sorry, your 3 chances ran out!";
              exit(EXIT_FAILURE);
          }

          std::cout << "Invalid input. Please try again and type either y or n.\n";
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
      
       std::cout << "Invalid input. Please try again and type either y or n.\n";
       continue;
      }
       
         bool valid {simulateOption == 'y' || simulateOption == 'n'};
         if (valid) {

           cout << "That is an acceptable response!";                                                                  //The program checks if the output is acceptable or not
           return simulateOption;
         } else {

           if (simulateAttempts == simulateChances) {

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
