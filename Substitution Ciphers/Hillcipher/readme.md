# Hill Cipher

## Overview

The Hill cipher is a polygraphic substitution cipher based on linear algebra, developed by the mathematician Lester Hill in 1929. This cipher uses matrix arithmetic to encrypt and decrypt messages, allowing for the hiding of letter frequency patterns. This README provides an overview of the concepts, algorithms, and examples related to the Hill cipher.

## Concepts from Linear Algebra

The Hill cipher operates using matrices and vectors in modular arithmetic (mod 26 for the English alphabet). The key components are:

#### Matrix Inversion:An inverse does not always exist; it exists only if the determinant of the matrix is nonzero.
#### Determinant
#### Inversion Formula
## Hill Cipher Algorithm

### Encryption

The Hill cipher encrypts \( m \) successive plaintext letters into \( m \) ciphertext letters using a key matrix \( K \) of size \( m \times m \). The substitution is defined by the equations:
This can be expressed in matrix form as:

\[
C = P*Kmod 26
\]

Where \( C \) and \( P \) are row vectors representing ciphertext and plaintext, respectively.

### Decryption

To decrypt, the inverse of the key matrix \( K \) is used:

\[
P = C*K^{-1} \mod 26
\]

### Example

Given the plaintext **"paymoremoney"** and the key matrix


1. Represent the first three letters of the plaintext as the vector (where \( a = 0, b = 1, ..., z = 25 \)).
2. Perform the matrix multiplication:
3. Continuing this process gives the full ciphertext: **"RRLMWBKASPDH"**.

### Known Plaintext Attack

While the Hill cipher is robust against ciphertext-only attacks, it can be broken with known plaintext attacks. By obtaining plaintext-ciphertext pairs and forming a matrix equation, the key matrix can be determined if the plaintext matrix is invertible.

## Conclusion

The Hill cipher is a strong encryption technique that uses linear algebra concepts to enhance security. It effectively hides single-letter frequencies and can also obscure two-letter frequencies with larger matrices. However, its vulnerability to known plaintext attacks highlights the need for careful key management and additional security measures in practical applications.
