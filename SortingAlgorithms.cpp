#include <iostream>
using namespace std;

/* Feb 9 2019
 * Laurent Lao
 * Learning C++ through https://github.com/karan/Projects
 * Merge sort and Bubble sort
 * Implement two types of sorting algorithms: Merge sort and bubble sort.
 * Merge sort is sorting algorithm which reduces its big O with a divide and conquer method, it uses recursion.
 * Bubble sort is a simple sorting algorithm which swaps elements until elements are sorted.
 * This implementation lets the user choose between either algorithms for sorting.
 */

// ** Function declarations **
int promptForArraySize();
void printArray(int *, int);
int promptForSortingChoice();
void run_mergeSort(int []);
void run_bubbleSort(int []);

int main()
{
    int arraySize = promptForArraySize();
    int arrayOfIntegers[arraySize];
    
    // Prompting for elements
    for (int index = 0; index < arraySize; index++)
    {
        cout << "Enter integer " << index << ": ";
        cin >> arrayOfIntegers[index];
    }
    
    // Make a copy of original array for reference
    int originalArrayOfIntegers[arraySize];
    for (int index = 0; index < arraySize; index++)
    {
        originalArrayOfIntegers[index] = arrayOfIntegers[index];
    }
    
    // Display original array
    cout << "\nThis is the array that you've entered: ";
    printArray(originalArrayOfIntegers, arraySize);
    cout << "\n";
    
    // Display a menu to choose sorting algorithm, then run selected sort
    switch (promptForSortingChoice())
    {
        case 1:
            run_mergeSort(arrayOfIntegers);
            break;
        case 2:
            run_bubbleSort(arrayOfIntegers);
            break;
    }
    
    // Printing original array and sorted array
    cout << "\n\n";
    cout << "Your original array: ";
    printArray(originalArrayOfIntegers, arraySize);
    cout << "The sorted array: ";
    printArray(arrayOfIntegers, arraySize);
    
    // End of program
    return 0;
}

// ** Function implementations **

// Prompt for the size of an array bigger than 1
int promptForArraySize()
{
    int arraySize = 0;
    
    bool isValid = false;
    do
    {
        cout << "Please enter an array size: ";
        cin >> arraySize;
        
        if (arraySize > 1)
        {
            isValid = true;
            return arraySize;
        }
        else
        {
            cout << "Invalid size.\n";
        }
    } while (!isValid);
}

// Print the elements of the array
void printArray(int array[], int arraySize)
{
    for (int index = 0; index < arraySize; index++)
    {
        // Adding a comma between elements
        if (index != 0)
        {
            cout << ", ";
        }
        
        // Printing the element
        cout << array[index];
    }
    
    cout << "\n";
}

// Displays a menu to select algorithm, prompts for correct choice and return the choice as an int
int promptForSortingChoice()
{
    int userChoice = 0;
    const int NUM_OF_CHOICES = 2;
    bool isValid = false;
    
    do
    {
        // Display Menu
        cout << "Choose a sorting algorithm" << endl;
        cout << "\t1. Merge Sort" << endl;
        cout << "\t2. Bubble Sort" << endl;
        cout << "Enter selection: ";
        
        cin >> userChoice;
        
        // Check input before returning
        if (userChoice >= 1 && userChoice <= NUM_OF_CHOICES)
        {
            isValid = true;
            return userChoice;
        }
        else
        {
            cout << "Invalid choice.\n\n";
        }
    } while (!isValid);
}

// To run Merge Sort
void run_mergeSort(int array[])
{
    // Debug
    cout << "\n*** Running Merge Sort (WIP) ***";
}

// To run Bubble Sort
void run_bubbleSort(int array[])
{
    // Debug
    cout << "\n*** Running Bubble Sort (WIP) ***";
}