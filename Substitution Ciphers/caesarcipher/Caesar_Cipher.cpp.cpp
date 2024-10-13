#include <iostream>
#include <string>
#include <cctype> // Include for character functions

using namespace std;

// Function to encrypt a string using Caesar Cipher
string encrypt(const string& text, int key) {
    string result = text; // Create a copy of the input text
    key = key % 26; // Normalize key to be within 0-25

    // Iterate through each character in the text
    for (char& c : result) {
        if (isalpha(c)) { // Check if the character is an alphabet
            char base = isupper(c) ? 'A' : 'a'; // Determine if it's uppercase or lowercase
            c = (c - base + key) % 26 + base; // Encrypt the character
        }
    }
    return result; // Return the encrypted string
}

// Function to decrypt a string using Caesar Cipher
string decrypt(const string& text, int key) {
    string result = text; // Create a copy of the input text
    key = key % 26; // Normalize key to be within 0-25

    // Iterate through each character in the text
    for (char& c : result) {
        if (isalpha(c)) { // Check if the character is an alphabet
            char base = isupper(c) ? 'A' : 'a'; // Determine if it's uppercase or lowercase
            c = (c - base - key + 26) % 26 + base; // Decrypt the character
        }
    }
    return result; // Return the decrypted string
}

int main() {
    int choice;
    string inputText;
    int key;

    cout << R"( 
   _____                             _____ _       _               
  / ____|                           / ____(_)     | |              
 | |     __ _  ___ ___  __ _ _ __  | |     _ _ __ | |__   ___ _ __ 
 | |    / _` |/ _ / __|/ _` | '__| | |    | | '_ \| '_ \ / _ | '__|
 | |___| (_| |  __\__ | (_| | |    | |____| | |_) | | | |  __| |   
  \_____\__,_|\___|___/\__,_|_|     \_____|_| .__/|_| |_|\___|_|   
                                            | |                    
                                            |_|                    

                                            )" << endl;

    while (true) {
        cout << "\nPlease choose an option:\n";
        cout << "1 = Encrypt a string.\n";
        cout << "2 = Decrypt a string.\n";
        cout << "3 = Exit.\n";
        cin >> choice;

        if (choice == 3) {
            break; // Exit the loop
        }

        cout << "Please enter a string: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, inputText); // Get the entire line including spaces

        cout << "\nPlease enter the key value for shifting: ";
        cin >> key; // Get the key from the user

        switch (choice) {
            case 1: // Encrypting a string
                {
                    string encryptedText = encrypt(inputText, key);
                    cout << "\nEncrypted string: " << encryptedText << endl;
                }
                break;

            case 2: // Decrypting a string
                {
                    string decryptedText = decrypt(inputText, key);
                    cout << "\nDecrypted string: " << decryptedText << endl;
                }
                break;

            default:
                cout << "\nInvalid Input !!!\n";
        }
    }

    return 0;
}

