# Polyalphabetic Ciphers

Polyalphabetic ciphers are encryption techniques that use multiple substitution alphabets to enhance the security of the encrypted message. Unlike monoalphabetic ciphers, where each letter in the plaintext is replaced by a single corresponding letter in the ciphertext, polyalphabetic ciphers utilize a sequence of alphabets based on a keyword. This method significantly complicates frequency analysis attacks, making it more secure against cryptanalysis.

## How Polyalphabetic Ciphers Work

### Vigenère Cipher

The **Vigenère cipher** is one of the most well-known polyalphabetic ciphers. It uses a keyword to determine the shift for each letter in the plaintext. The key is repeated to match the length of the plaintext, allowing for varying shifts.

#### How It Works
1. **Keyword Repetition**: The keyword is repeated to align with the length of the plaintext.
   - For example, if the plaintext is "HELLO" and the keyword is "KEY", the aligned key becomes "KEYKE".
   
2. **Encryption Formula**: Each letter in the plaintext is shifted according to the corresponding letter in the key using the formula:
   \[
   C_i = (P_i + K_i) mod 26
   \]
   Where:
   - \(C_i\) is the ith character of the ciphertext,
   - \(P_i\) is the ith character of the plaintext (converted to a number where A=0, B=1, ..., Z=25),
   - \(K_i\) is the ith character of the key (also converted similarly).

3. **Decryption Formula**: To retrieve the original plaintext, the reverse operation is applied:
   \[
   P_i = (C_i - K_i + 26) mod 26
   \]

### Vernam Cipher

The **Vernam cipher**, also known as the one-time pad, is a symmetric-key cipher that uses a random key that is as long as the plaintext. Each character in the plaintext is combined with a character from the key to produce the ciphertext.

#### How It Works
1. **Unique Key Generation**: A random key is generated, which is the same length as the plaintext. Each character of the plaintext corresponds to a character in the key.
   
2. **Encryption Formula**: The encryption is done using the XOR operation or modular arithmetic:
   \[
   C_i = P_i XOR K_i
   \]
   Where:
   - \(C_i\) is the ith character of the ciphertext,
   - \(P_i\) is the ith character of the plaintext,
   - \(K_i\) is the ith character of the key.

3. **Decryption Formula**: Since XOR is its own inverse, the same operation is used for decryption:
   \[
   P_i = C_i XOR K_i
   \]

### Autokey Cipher

The **Autokey cipher** is a variation of the Vigenère cipher that eliminates the repetition of keys by using the plaintext itself as part of the key. This creates a longer and more complex key sequence.

#### How It Works
1. **Keyword and Plaintext Combination**: The initial keyword is followed by the plaintext, which forms the complete key. This means the key expands as the plaintext is processed.
   - For example, if the plaintext is "HELLO" and the key is "KEY", the key used for encryption becomes "KEYHEL".

2. **Encryption Formula**: The encryption is similar to the Vigenère cipher, using:
   \[
   C_i = (P_i + K_i) mod 26
   \]
   Where \(K_i\) is now derived from the expanding key.

3. **Periodic Nature**: The Autokey cipher maintains a periodic nature, meaning the plaintext continuously contributes to the key as it is processed, making the key non-repetitive.

4. **Decryption Formula**: The decryption process is also similar, where the ciphertext is transformed back into plaintext using the same principles:
   \[
   P_i = (C_i - K_i + 26) mod 26
   \]

## Conclusion

Polyalphabetic ciphers, including the Vigenère cipher, Vernam cipher, and Autokey cipher, significantly enhance the security of encrypted messages by using varying keys and complex patterns. Understanding these ciphers is crucial for grasping fundamental concepts in cryptography and information security.
