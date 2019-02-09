#include <iostream>

/* Feb 9 2019
 * Laurent Lao
 * Learning C++ through https://github.com/karan/Projects
 * Collatz Conjuncture
 * Start with a number n > 1. Find the number of steps it takes to reach one(1) using the following
 * process: If n is even, divide it by 2. If n is odd, multiply it by 3 and add 1.
 */

int main()
{
    // Todo: Program accepts user inputs
    // Hard-coding a number
    int chosenNumber = 27;

    // Do operations until chosenNumber = 1 and keep count
    int chosenNumber_start = chosenNumber;
    int counter = 0;
    while (chosenNumber != 1)
    {
        // Increment counter
        counter++;
        std::cout << "Step " << counter << ": " << chosenNumber << " is ";
        // When number is even
        if (chosenNumber % 2 == 0)
        {
            chosenNumber /= 2;
            std::cout << "even. Divided by 2: " << chosenNumber;
        }
        // When number is odd
        else
        {
            chosenNumber = chosenNumber * 3 + 1;
            std::cout << "odd. Multiplied by 3 then adding 1: " << chosenNumber;
        }
        
        // Creating new line
        std::cout << "\n";
    }
    
    // Print results
std::cout << "\nIt took " << counter << " steps to make " << chosenNumber_start << " equal to 1 using the\nCollatz conjuncture>";
    return 0;
}