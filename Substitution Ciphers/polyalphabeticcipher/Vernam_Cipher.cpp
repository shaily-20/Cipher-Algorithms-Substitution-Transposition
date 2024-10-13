#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class VernamCipher {
public:
    string encrypt(const string& plaintext, const string& key) {
        string ciphertext = "";
        for (size_t i = 0; i < plaintext.size(); i++) {
            ciphertext += (plaintext[i] ^ key[i]);
        }
        return ciphertext;
    }

    string decrypt(const string& ciphertext, const string& key) {
        string plaintext = "";
        for (size_t i = 0; i < ciphertext.size(); i++) {
            plaintext += (ciphertext[i] ^ key[i]);
        }
        return plaintext;
    }

    string generateKey(const string& plaintext) {
        string key = "";
        srand(time(0));
        for (size_t i = 0; i < plaintext.size(); i++) {
            key += char(rand() % 256); // Generate a random character
        }
        return key;
    }
};

int main() {
    VernamCipher vc;
    string plaintext = "HELLO";
    string key = vc.generateKey(plaintext);
    
    string ciphertext = vc.encrypt(plaintext, key);
    cout << "Ciphertext: ";
    for (char c : ciphertext) {
        cout << int(c) << " "; // Display ASCII values
        Cout << char(c) << " "; //Display Char
    }
    cout << endl;

    string decryptedText = vc.decrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

