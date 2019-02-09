#include <iostream>
using namespace std;

/* Feb 9 2019
 * Laurent Lao
 * Learning C++ through https://github.com/karan/Projects
 * Ceasar Cipher
 * Implement a Caesar cipher, both encoding and decoding. The key is an integer from 1 to 25. This cipher rotates the
 * letters of the alphabet (A to Z). The encoding replaces each letter with the 1st to 25th next letter in the alphabet
 * (wrapping Z to A). So key 2 encrypts "HI" to "JK", but key 20 encrypts "HI" to "BC". This simple "monoalphabetic
 * substitution cipher" provides almost no security, because an attacker who has the encoded message can either use
 * frequency analysis to guess the key, or just try all 25 keys.
 */

// ** Function declarations **
int promptEncryptOrDecrypt();
void run_encrypt(char []);
void run_decrypt(char []);
void ceasarWithKey(char [], int, bool);

// ** CONST declaration **
const int MAX_CHAR_SIZE_INPUT = 256;

int main()
{
    char stringInputted[MAX_CHAR_SIZE_INPUT];
    
    // Prompt user for a string and store into a char array stringInputted
    cout << "Enter the string to be encrypted/decrypted (Max " << MAX_CHAR_SIZE_INPUT << " characters): ";
    cin.getline(stringInputted, 256);
    
    // Copy the char array for reference
    char original_stringInputted[256];
    for (int index = 0; index < MAX_CHAR_SIZE_INPUT; index++)
    {
        original_stringInputted[index] = stringInputted[index];
        
        if (stringInputted[index] == '\n')
        {
            break;
        }
    }
    
    // Choose either Encrypt or Decrypt and run appropriate algorithm
    switch (promptEncryptOrDecrypt())
    {
        case 1:
            run_encrypt(stringInputted);
            break;
        case 2:
            run_decrypt(stringInputted);
            break;
    }
    
    // Printing the original string
    cout << "\n\nThe original string is: " << original_stringInputted << "\n\n";
    
    // End of Program
    return 0;
}

// ** Function implementations **

// Displays a menu to select if wants to Encrypt or Decrypt, prompts for correct choice and return the choice as an int
int promptEncryptOrDecrypt()
{
    int userChoice = 0;
    const int NUM_OF_CHOICES = 2; // change this to reflect number of choices
    bool isValid = false;
    
    do
    {
        // Display Menu
        cout << "What do you want to do?" << endl;
        cout << "\t1. Encrypt" << endl;
        cout << "\t2. Decrypt" << endl;
        // add more choices here
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
    }
    while (!isValid);
}

// Displays a menu to select if user knows the key or not
int promptKnowsKey()
{
    int userChoice = 0;
    const int NUM_OF_CHOICES = 2; // change this to reflect number of choices
    bool isValid = false;
    
    do
    {
        // Display Menu
        cout << "Do you know the key?" << endl;
        cout << "\t1. Yes" << endl;
        cout << "\t2. No" << endl;
        // add more choices here
        cout << "Enter selection (1 or 2): ";
        
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
    }
    while (!isValid);
}

// Prompt for a key between 1 to 25
int promptForAKey()
{
    int userKey = 0;
    bool isValid = false;
    
    do
    {
        cout << "Enter a key between 1 and 25: ";
        cin >> userKey;
        
        if (userKey >= 1 && userKey <= 25)
        {
            isValid = true;
            return userKey;
        }
        else
        {
            cout << "Invalid input\n";
        }
        
    }
    while (!isValid);
}

void run_encrypt(char stringInputted[])
{
    // Debug
    cout << "** Cesar Encryption **\n" << endl;
    
    // Get a key from user and encrypt the string
    ceasarWithKey(stringInputted, promptForAKey(), true);
    
    // Print the modified string
    cout << "The encrypted string is: " << stringInputted;
    
}

void run_decrypt(char stringInputted[])
{
    cout << "** Ceasar Decryption ** \n" << endl;
    
    // Prompting user whether they know the key or they want to try all the keys
    switch (promptKnowsKey())
    {
        case 1:
            // User knows the key, decrypt and display
            cout << "You know the key.\n";
            ceasarWithKey(stringInputted, promptForAKey(), false);
            cout << "The decrypted string is: " << stringInputted;
            break;
        case 2:
            // User doesn't know the key, decrypt with all possible keys and display each results
            for (int key = 1; key <= 25; key++)
            {
                // Copy the input to manipulate
                char decryptThis [MAX_CHAR_SIZE_INPUT];
                for (int index = 0; index < MAX_CHAR_SIZE_INPUT; index++)
                {
                    decryptThis[index] = stringInputted[index];
                    
                    if (stringInputted[index] == '\n')
                    {
                        break;
                    }
                }
                
                // Pass the copied input to be decrypted into Ceasar with key
                ceasarWithKey(decryptThis, key, false);
                
                // Printing output
                cout << "Decrypting with key\t" << key << ":\t" << decryptThis << endl;
            }
            break;
            
    }
}

void ceasarWithKey(char stringInputted[], int key, bool isEncryption)
{
    // Modify key according to whether it is an encryption or decryption
    if (!isEncryption)
    {
        key = 26 - key;
    }
    
    for (int index = 0; index < MAX_CHAR_SIZE_INPUT; index++)
    {
        char charToChange = stringInputted[index];
        
        // Lower case behaviour
        if (charToChange >= 'a' && charToChange <= 'z')
        {
            //Change for lower case
            charToChange = (charToChange + key) % ('z' + 1);
            if (charToChange < 'a')
            {
                charToChange += 'a';
            }
            stringInputted[index] = charToChange;
        }
        // Upper case behaviour
        else if (charToChange >= 'A' && charToChange <= 'Z')
        {
            // Change for upper case
            charToChange = (charToChange + key) % ('Z' + 1);
            if (charToChange < 'A')
            {
                charToChange += 'A';
            }
            stringInputted[index] = charToChange;
        }
        // Stop at new line character
        else if (charToChange == '\n')
        {
            break;
        }
        // Do nothing if not in alphabet
        else
        {
            continue;
        }
    }
}