#include <iostream>
#include <string>
using namespace std;

class AutokeyCipher {
public:
    string encrypt(const string& plaintext, const string& key) {
        string ciphertext = "";
        string fullKey = key + plaintext; // Create full key by appending plaintext
        
        for (size_t i = 0; i < plaintext.length(); i++) {
            char p = plaintext[i];
            char k = fullKey[i + key.length()]; // Use part of the plaintext as key
            ciphertext += char((toupper(p) + toupper(k)) % 26 + 'A');
        }
        return ciphertext;
    }

    string decrypt(const string& ciphertext, const string& key) {
        string plaintext = "";
        string fullKey = key; // Start with the initial key

        for (size_t i = 0; i < ciphertext.length(); i++) {
            char c = ciphertext[i];
            char k = fullKey[i]; // Use part of the full key
            plaintext += char((c - k + 26) % 26 + 'A');
            fullKey += plaintext[i]; // Append to the full key
        }
        return plaintext;
    }
};

int main() {
    AutokeyCipher ac;
    string plaintext = "HELLO";
    string key = "KEY";

    string ciphertext = ac.encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = ac.decrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

