// C++ program to illustrate Rail Fence Cipher
// Encryption and Decryption with user input
#include <iostream>
#include <string>
using namespace std;

// Function to encrypt a message using Rail Fence Cipher
string encryptRailFence(string text, int key)
{
    // Create the matrix to cipher plain text
    char rail[key][(text.length())];

    // Filling the rail matrix to distinguish filled spaces from blank ones
    for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';

    // To find the direction
    bool dir_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < text.length(); i++)
    {
        // Reverse the direction if we've just filled the top or bottom rail
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;

        // Fill the corresponding alphabet in the rail matrix
        rail[row][col++] = text[i];

        // Move to the next row depending on the direction
        dir_down ? row++ : row--;
    }

    // Now construct the cipher using the rail matrix
    string result;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            if (rail[i][j] != '\n')
                result.push_back(rail[i][j]);

    return result;
}

// Function to decrypt a Rail Fence Cipher
string decryptRailFence(string cipher, int key)
{
    // Create the matrix to cipher plain text
    char rail[key][cipher.length()];

    // Filling the rail matrix to distinguish filled spaces from blank ones
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            rail[i][j] = '\n';

    // To find the direction
    bool dir_down;
    int row = 0, col = 0;

    // Mark the places with '*'
    for (int i = 0; i < cipher.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;

        // Place the marker
        rail[row][col++] = '*';

        // Move to the next row depending on direction
        dir_down ? row++ : row--;
    }

    // Now we can fill the rail matrix with the actual cipher characters
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (rail[i][j] == '*' && index < cipher.length())
                rail[i][j] = cipher[index++];

    // Now read the matrix in zig-zag manner to construct the resultant text
    string result;
    row = 0, col = 0;
    for (int i = 0; i < cipher.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;

        // Add the character to result if it's not '*'
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);

        // Move to the next row depending on direction
        dir_down ? row++ : row--;
    }
    return result;
}

// Driver function to perform encryption and decryption based on user input
int main()
{
    string plaintext, ciphertext;
    int key;

    // Take user input
    cout << "Enter the plaintext to encrypt: ";
    getline(cin, plaintext);

    cout << "Enter the depth (key) for encryption: ";
    cin >> key;

    // Perform encryption
    ciphertext = encryptRailFence(plaintext, key);
    cout << "Encrypted Text: " << ciphertext << endl;

    // Perform decryption
    string decryptedText = decryptRailFence(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

