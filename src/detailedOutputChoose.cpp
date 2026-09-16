#include <iostream>
#include <limits>
#include <cstdlib>

#include "detailedOutputChoose.h"
using namespace std;

constexpr int outputChances = 3;               //Initialising chances to 3 as maximum
using yesOrNo = char;                      //Defining yesOrNo as an alias for type char
using chances = int;                             //Defining chances as an alias for type int

namespace detailedOutput {

  yesOrNo detailedOutputChoose() {

     chances outputAttempts = 0;
     while (outputAttempts < outputChances) {

         cout << "Do you want to see the full simulation summary before starting yes or no (please please only type y or n both lower case?)";
         yesOrNo option {};
         cin >> option;
         outputAttempts++;

         if (!std::cin) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                           //Warns if no input has been typed
           
          if (outputAttempts == outputChances) {
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
       
         bool valid {option == 'y' || option == 'n'};
         if (valid) {

           cout << "That is an acceptable response!";                                                                  //The program checks if the output is acceptable or not
           return option;
         } else {

           if (outputAttempts == outputChances) {

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
