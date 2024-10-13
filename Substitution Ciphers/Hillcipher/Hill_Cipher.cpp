#include <iostream>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <string>

using namespace std;

class HillCipher {
public:
    // Method to accept key matrix
    static vector<vector<int>> getKeyMatrix(int size) {
        vector<vector<int>> keyMatrix(size, vector<int>(size));
        cout << "Enter the key matrix values (row by row, space-separated):\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> keyMatrix[i][j];
                keyMatrix[i][j] = keyMatrix[i][j] % 26; // Ensure values are within 0-25
            }
        }
        return keyMatrix;
    }

    // Method to check whether the key matrix is valid (det=0)
    static void isValidMatrix(const vector<vector<int>>& keyMatrix) {
        int det = keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0];
        if (det == 0) {
            throw runtime_error("Det equals to zero, invalid key matrix!");
        }
    }

    // Method to calculate the reverse key matrix
    static vector<vector<int>> reverseMatrix(const vector<vector<int>>& keyMatrix) {
        int det = (keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0]) % 26;
        if (det < 0) det += 26;  // Ensure positive determinant

        // Find the modular multiplicative inverse of det mod 26
        int invDet = -1;
        for (int i = 1; i < 26; i++) {
            if ((det * i) % 26 == 1) {
                invDet = i;
                break;
            }
        }
        if (invDet == -1) {
            throw runtime_error("No modular inverse found for the determinant!");
        }

        // Calculate the inverse matrix using the adjugate matrix and modular inverse
        vector<vector<int>> revMatrix(2, vector<int>(2));
        revMatrix[0][0] = (keyMatrix[1][1] * invDet) % 26;
        revMatrix[0][1] = (-keyMatrix[0][1] * invDet) % 26;
        revMatrix[1][0] = (-keyMatrix[1][0] * invDet) % 26;
        revMatrix[1][1] = (keyMatrix[0][0] * invDet) % 26;

        // Ensure all values are non-negative
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (revMatrix[i][j] < 0) {
                    revMatrix[i][j] += 26;
                }
            }
        }

        return revMatrix;
    }

    // Method to print the result
    static void echoResult(const string& label, const vector<int>& phrase) {
        cout << label;
        for (size_t i = 0; i < phrase.size(); i++) {
            cout << static_cast<char>(phrase[i] + 'A'); // convert to character
            if (i + 1 < phrase.size()) {
                cout << "-";
            }
        }
        cout << endl;
    }

    // Method for encryption
    static void encrypt(const string& phrase, const vector<vector<int>>& keyMatrix) {
        vector<int> phraseToNum;
        vector<int> phraseEncoded;

        // Clean and prepare the phrase
        string cleanPhrase;
        for (char c : phrase) {
            if (isalpha(c)) {
                cleanPhrase += toupper(c); // convert to uppercase
            }
        }

        // If phrase length is not even, add an 'X'
        if (cleanPhrase.length() % 2 != 0) {
            cleanPhrase += 'X';
        }

        // Convert characters to numbers
        for (char c : cleanPhrase) {
            phraseToNum.push_back(c - 'A'); // A=0, B=1, ..., Z=25
        }

        // Encrypt the phrase using the key matrix
        for (size_t i = 0; i < phraseToNum.size(); i += 2) {
            int x = (keyMatrix[0][0] * phraseToNum[i] + keyMatrix[0][1] * phraseToNum[i + 1]) % 26;
            int y = (keyMatrix[1][0] * phraseToNum[i] + keyMatrix[1][1] * phraseToNum[i + 1]) % 26;
            phraseEncoded.push_back(x);
            phraseEncoded.push_back(y);
        }

        echoResult("Encoded ciphertext: ", phraseEncoded);
    }

    // Method for decryption
    static void decrypt(const string& phrase, const vector<vector<int>>& keyMatrix) {
        vector<int> phraseToNum;
        vector<int> phraseDecoded;

        // Clean and prepare the phrase
        string cleanPhrase;
        for (char c : phrase) {
            if (isalpha(c)) {
                cleanPhrase += toupper(c); // convert to uppercase
            }
        }

        for (size_t i = 0; i < cleanPhrase.length(); i++) {
            phraseToNum.push_back(cleanPhrase[i] - 'A'); // A=0, B=1, ..., Z=25
        }

        vector<vector<int>> revKeyMatrix = reverseMatrix(keyMatrix);
        // Find the product per pair of the phrase with the reverse key matrix modulo 26
        for (size_t i = 0; i < phraseToNum.size(); i += 2) {
            int x = (revKeyMatrix[0][0] * phraseToNum[i] + revKeyMatrix[0][1] * phraseToNum[i + 1]) % 26;
            int y = (revKeyMatrix[1][0] * phraseToNum[i] + revKeyMatrix[1][1] * phraseToNum[i + 1]) % 26;
            phraseDecoded.push_back(x);
            phraseDecoded.push_back(y);
        }

        echoResult("Decoded plaintext: ", phraseDecoded);
    }
};

// Main method
int main() {
    string opt, phrase;
    int size;

    cout << "Hill Cipher Implementation" << endl;
    cout << "-------------------------" << endl;

    while (true) {
        cout << "Enter the size of the key matrix (2 for 2x2, 3 for 3x3, or any other positive integer): ";
        cin >> size;

        if (size < 2) {
            cout << "Size must be 2 or greater. Please try again." << endl;
            continue;
        }

        // Only supporting 2x2 for now for simplicity
        if (size != 2) {
            cout << "Currently, only 2x2 matrices are supported." << endl;
            continue;
        }

        vector<vector<int>> keyMatrix = HillCipher::getKeyMatrix(size);
        HillCipher::isValidMatrix(keyMatrix);

        cout << "1. Encrypt plaintext\n";
        cout << "2. Decrypt ciphertext\n";
        cout << "Select your choice: ";
        cin >> opt;

        cout << "Enter the text (only letters will be considered): ";
        cin.ignore(); // Ignore newline from previous input
        getline(cin, phrase); // Use getline to allow spaces in input

        if (opt == "1") {
            HillCipher::encrypt(phrase, keyMatrix);
        } else if (opt == "2") {
            HillCipher::decrypt(phrase, keyMatrix);
        } else {
            cout << "Invalid option. Exiting." << endl;
            break; // Exit if input is not valid
        }
    }
    return 0;
}

