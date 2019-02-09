#include <iostream>

/* Feb 9 2019
 * Laurent Lao
 * Learning C++ through https://github.com/karan/Projects
 * Fizz Buzz
 * Write a program that prints the numbers from 1 to 100. But for multiples of three print “Fizz”
 * instead of the number and for the multiples of five print “Buzz”. For numbers which are multi-
 * ples of both three and five print “FizzBuzz”.
 */

int main() {

    for (int counter = 1; counter < 100; counter++)
    {
        // Check if multiples
        bool isMultipleOfThree = (counter % 3 == 0);
        bool isMultipleOfFive = (counter % 5 == 0);

        // Print Fizz if only multiple of three
        if (isMultipleOfThree && !isMultipleOfFive)
        {
            std::cout << "Fizz\n";
        }
        // If multiples of five print "Buzz"
        else if (!isMultipleOfThree && isMultipleOfFive)
        {
            std::cout << "Buzz\n";
        }
        // If multiples of three and five print "FizzBuzz"
        else if (isMultipleOfThree && isMultipleOfFive)
        {
            std::cout << "FizzBuzz\n";
        }
        // If not a multiple of three nor five, print the number
        else
        {
            std::cout << counter << "\n";
        }
    }
    return 0;

}