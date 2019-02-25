#include <iostream>

using namespace std;

/* Feb 25 2019
 * Laurent Lao
 * Learning C++ through https://github.com/karan/Projects
 * Number Names
 * Write a program that takes an integer and displays the English name of that value. You should support both positive and
 * negative numbers, in the range supported by a 32-bit integer (approximately -2 billion to 2 billion).
 * I practiced using classes in this implementation
 * */

class Number
{
    // These are private
    
    long number;
    
    bool negativeNumber = false;
    
    void print_threeByThree(int);
    
    string digit_toString(int);
    
    string tens_toString(int);


public:
    // These are public
    
    Number(long);
    
    void print_english_number();
};

Number::Number(long num_param)
{
    // If number is negative -> Transform the number into a positive integer and switch the negativeNumber flag
    if (num_param < 0)
    {
        negativeNumber = true;
        number = num_param * -1;
    }
    else
    {
        number = num_param;
    }
    
}

void Number::print_english_number()
{
    long billions = 0;
    int millions = 0;
    int thousands = 0;
    int hundreds = 0;
    
    // it's a negative number
    if (negativeNumber)
    {
        cout << "minus ";
    }
    
    // print zero if number is zero
    if (number == 0)
    {
        cout << "zero";
        return;
    }
    
    if (number >= 1000000000)
    {
        billions = (number / 1000000000);
    }
    if (number >= 1000000)
    {
        millions = (int) ((number % 1000000000) / 1000000);
    }
    if (number >= 1000)
    {
        thousands = (int) ((number % 1000000) / 1000);
    }
    hundreds = (int) (number % 1000);
    
    if (billions > 0)
    {
        int billions_int = (int) billions;
        print_threeByThree(billions_int);
        cout << " billion ";
    }
    
    if (millions > 0)
    {
        print_threeByThree(millions);
        cout << " million ";
    }
    
    if (thousands > 0)
    {
        print_threeByThree(thousands);
        cout << " thousand ";
    }
    
    if (hundreds > 0)
    {
        print_threeByThree(hundreds);
    }
}

void Number::print_threeByThree(int number_param)
{
    
    int hundredsOnly = number_param / 100;
    int tens = number_param % 100;
    int tensOnly = (number_param % 100) / 10;
    int digitsOnly = number_param % 10;
    
    bool hasHundreds = hundredsOnly > 0;
    bool hasTens = tensOnly > 0;
    bool hasDigit = digitsOnly > 0;
    
    if (hasHundreds && !hasTens && !hasDigit)
    {
        cout << digit_toString(hundredsOnly) << " hundred";
    }
    else if (hasHundreds)
    {
        cout << digit_toString(hundredsOnly) << " hundred ";
    }
    
    if (hasHundreds && !hasTens && hasDigit)
    {
        cout << "and " << tens_toString(tens);
    }
    else if (hasTens)
    {
        cout << tens_toString(tens);
    }
    else if (!hasHundreds && hasDigit)
    {
        cout << digit_toString(digitsOnly);
    }
}

string Number::digit_toString(int digit)
{
    switch (digit)
    {
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
    }
}

string Number::tens_toString(int tens)
{
    string tens_toString = "";
    int tensOnly = 0;
    int digitsOnly = tens % 10;
    
    // If tens >= 20, revert back to single digit, if between 10 and 20 (exclusive), keep format
    if (tens >= 20)
    {
        tensOnly = tens / 10;
    }
    else if (tens >= 10)
    {
        tensOnly = tens;
    }
    
    // If tensOnly doesn't equal to 0, either add to the string then ten position or return the string with 10,11...19.
    if (tensOnly != 0)
    {
        switch (tensOnly)
        {
            case 2:
                tens_toString.append("twenty");
                break;
            case 3:
                tens_toString.append("thirty");
                break;
            case 4:
                tens_toString.append("forty");
                break;
            case 5:
                tens_toString.append("fifty");
                break;
            case 6:
                tens_toString.append("sixty");
                break;
            case 7:
                tens_toString.append("seventy");
                break;
            case 8:
                tens_toString.append("eighty");
                break;
            case 9:
                tens_toString.append("ninety");
                break;
            case 10:
                return "ten";
            case 11:
                return "eleven";
            case 12:
                return "twelve";
            case 13:
                return "thirteen";
            case 14:
                return "fourteen";
            case 15:
                return "fifteen";
            case 16:
                return "sixteen";
            case 17:
                return "seventeen";
            case 18:
                return "eighteen";
            case 19:
                return "nineteen";
        }
    }
    else
    {
        // if digits is not 0, just return that digit
        if (digitsOnly != 0)
        {
            return digit_toString(digitsOnly);
        }
    }
    
    // if this flow is reached, add "-" + the digit, or return the value (i.e. twenty) if there are no digits
    if (digitsOnly != 0)
    {
        // both += and append works in my compiler
        tens_toString += "-";
        // tens_toString.append("-");
        tens_toString.append(digit_toString(digitsOnly));
        return tens_toString;
    }
    else
    {
        return tens_toString;
    }
}

int main()
{
    long userNumber;
    std::cout << "Enter an integer to print: ";
    cin >> userNumber;
    
    // Implementation with Classes/Objects
    Number numberToPrint = Number(userNumber);
    numberToPrint.print_english_number();
    
    return 0;
}