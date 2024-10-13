#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; // Use the std namespace for convenience

#define SIZE 30 // Maximum size for strings

// Function to convert a string to lowercase
void toLowerCase(string &str) {
    for (char &c : str) {
        c = tolower(c); // Change each character to lowercase
    }
}

// Function to remove spaces from a string
void removeSpaces(string &str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // Remove spaces
}

// Function to generate the 5x5 key table
void generateKeyTable(const string &key, char keyT[5][5]) {
    vector<bool> used(26, false); // Track used letters
    int i = 0, j = 0;

    // Fill key table with letters from the key
    for (char ch : key) {
        if (ch == 'j') ch = 'i'; // Treat 'j' as 'i'
        if (!used[ch - 'a']) { // If the letter is not used
            used[ch - 'a'] = true; // Mark it as used
            keyT[i][j++] = ch; // Add it to the key table
            if (j == 5) { // Move to the next row if necessary
                j = 0;
                i++;
            }
        }
    }

    // Fill remaining letters of the alphabet
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (ch == 'j') continue; // Skip 'j'
        if (!used[ch - 'a']) { // If the letter is not used
            keyT[i][j++] = ch; // Add it to the key table
            if (j == 5) { // Move to the next row if necessary
                j = 0;
                i++;
            }
        }
    }
}

// Function to find positions of letters in the key table
void search(char keyT[5][5], char a, char b, int arr[]) {
    if (a == 'j') a = 'i'; // Treat 'j' as 'i'
    if (b == 'j') b = 'i'; // Treat 'j' as 'i'

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyT[i][j] == a) {
                arr[0] = i; // Row of 'a'
                arr[1] = j; // Column of 'a'
            } else if (keyT[i][j] == b) {
                arr[2] = i; // Row of 'b'
                arr[3] = j; // Column of 'b'
            }
        }
    }
}

// Function to prepare the plaintext
void prepare(string &str) {
    if (str.length() % 2 != 0) { // If the length is odd
        str += 'z'; // Add 'z' to make it even
    }
}

// Function to encrypt the plaintext
void encrypt(string &str, char keyT[5][5]) {
    int a[4]; // Array to hold positions of letters
    for (size_t i = 0; i < str.length(); i += 2) {
        search(keyT, str[i], str[i + 1], a);
        if (a[0] == a[2]) { // Same row
            str[i] = keyT[a[0]][(a[1] + 1) % 5]; // Move right
            str[i + 1] = keyT[a[0]][(a[3] + 1) % 5];
        } else if (a[1] == a[3]) { // Same column
            str[i] = keyT[(a[0] + 1) % 5][a[1]]; // Move down
            str[i + 1] = keyT[(a[2] + 1) % 5][a[1]];
        } else { // Rectangle formation
            str[i] = keyT[a[0]][a[3]]; // Swap columns
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

// Main function
int main() {
    string str = "ARMU"; // The message to encrypt
    string key = "monarchy"; // The keyword
    char keyT[5][5]; // 5x5 key table
    cout << "Plaintext: " << str << endl; // Display plaintext after preparation
    // Convert to lowercase and remove spaces
    toLowerCase(key);
    toLowerCase(str);
    removeSpaces(key);
    removeSpaces(str);

    // Prepare the plaintext
    prepare(str);

    // Generate the key table
    generateKeyTable(key, keyT);

    // Encrypt the plaintext
    encrypt(str, keyT);

    // Output the details
    
    cout << "Key: " << key << endl; // Display the key used
    cout << "Cipher text: " << str << endl; // Display the encrypted message

    return 0;
}

