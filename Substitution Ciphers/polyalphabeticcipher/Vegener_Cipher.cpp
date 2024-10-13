#include <iostream>
#include <string>
using namespace std;

class VigenereCipher {
public:
    string encrypt(const string& plaintext, const string& key) {
        string ciphertext = "";
        int keyIndex = 0;
        
        for (char p : plaintext) {
            if (isalpha(p)) {
                char offset = isupper(p) ? 'A' : 'a';
                int shift = toupper(key[keyIndex % key.length()]) - 'A';
                ciphertext += char((p - offset + shift) % 26 + offset);
                keyIndex++;
            } else {
                ciphertext += p; // Non-alpha characters are added unchanged
            }
        }
        return ciphertext;
    }

    string decrypt(const string& ciphertext, const string& key) {
        string plaintext = "";
        int keyIndex = 0;
        
        for (char c : ciphertext) {
            if (isalpha(c)) {
                char offset = isupper(c) ? 'A' : 'a';
                int shift = toupper(key[keyIndex % key.length()]) - 'A';
                plaintext += char((c - offset - shift + 26) % 26 + offset);
                keyIndex++;
            } else {
                plaintext += c; // Non-alpha characters are added unchanged
            }
        }
        return plaintext;
    }
};

int main() {
    VigenereCipher vc;
    string plaintext = "HELLO WORLD";
    string key = "KEY";
    
    string ciphertext = vc.encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = vc.decrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
