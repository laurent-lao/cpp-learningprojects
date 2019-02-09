#include <iostream>
using namespace std;

/* Feb 9 2019
 * Laurent Lao
 * Learning C++ through https://github.com/karan/Projects
 * Collatz Conjuncture
 * Start with a number n > 1. Find the number of steps it takes to reach one(1) using the following
 * process: If n is even, divide it by 2. If n is odd, multiply it by 3 and add 1.
 */

// ** Declaring functions **
int promptForNumber();

int main()
{
    // Prompt for a number over 1
    int chosenNumber = promptForNumber();

    // Do operations until chosenNumber = 1 and keep count
    int chosenNumber_start = chosenNumber;
    int counter = 0;
    while (chosenNumber != 1)
    {
        // Increment counter
        counter++;
        cout << "Step " << counter << ": " << chosenNumber << " is ";
        // When number is even
        if (chosenNumber % 2 == 0)
        {
            chosenNumber /= 2;
            cout << "even. Divided by 2: " << chosenNumber;
        }
        // When number is odd
        else
        {
            chosenNumber = chosenNumber * 3 + 1;
            cout << "odd. Multiplied by 3 then adding 1: " << chosenNumber;
        }
        
        // Creating new line
        cout << "\n";
    }
    
    // Print results
    cout << "\nIt took " << counter << " steps to make " << chosenNumber_start << " equal to 1 using the Collatz conjuncture";
    return 0;
}

// ** Function implementations **

// Prompts for a number greater than 1, loop if necessary
int promptForNumber()
{
    bool isCorrect = false;
    do
    {
        int chosenNumber;
        cout << "Enter a number greater than 1: ";
        cin >> chosenNumber;
        
        if (chosenNumber <= 1)
        {
            cout << "Invalid number, try again.\n";
        }
        else
        {
            isCorrect = true;
            return chosenNumber;
        }
    }
    while (!isCorrect);
}