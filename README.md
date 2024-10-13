# Cipher-Algorithms-Substitution-Transposition
A comprehensive collection of classic cipher algorithms, including detailed explanations and implementations of substitution and transposition ciphers.

## Overview
This repository explores classical cryptography, focusing on two major types of ciphers: **Substitution** and **Transposition**. The repository provides implementations and explanations for various cipher algorithms, making it an excellent resource for students, educators, and cryptography enthusiasts.

## Table of Contents
- Substitution Ciphers
  - Caesar Cipher
  - Vigenère Cipher
  - Monoalphabetic Cipher
  - Playfair Cipher
  - Vernam Cipher
  - Autokey Cipher
  - One-Time Pad
- Transposition Ciphers
  - Rail Fence Cipher
  - Columnar Transposition Cipher

## Substitution Ciphers

### Caesar Cipher
The Caesar Cipher is one of the simplest and most well-known encryption techniques. It replaces each letter in the plaintext by a letter some fixed number of positions down the alphabet.

**Formula**:
- For each letter in the plaintext \( P \), the ciphertext \( C \) is given by:
  
  \[
  C = (P + K) mod 26
  \]
  
Where:
- \( P \) is the position of the plaintext letter in the alphabet (0-indexed).
- \( K \) is the shift key.

**Example**:
- Plaintext: `HELLO`
- Key: `3`
- Ciphertext: `KHOOR`

### Vigenère Cipher
The Vigenère Cipher is a method of encrypting alphabetic text by using a simple form of polyalphabetic substitution. A keyword is used to dictate the shifting of letters.

**Formula**:
- For each letter in the plaintext \( P \) and the corresponding letter in the keyword \( K \):
  
  \[
  C = (P + K) mod 26
  \]

**Example**:
- Plaintext: `HELLO`
- Keyword: `KEY`
- Ciphertext: `RIJVS`

### Monoalphabetic Cipher
The Monoalphabetic Cipher is a substitution cipher where each letter of the plaintext is replaced by a letter with some fixed relationship to it. This type of cipher is more secure than the Caesar Cipher.

### Playfair Cipher
The Playfair Cipher is a digraph substitution cipher that encrypts pairs of letters (digraphs) instead of single letters.

**Example**:
- Plaintext: `HELLO`
- Key: `PLAYFAIR`
- Ciphertext: `CIPHE`

### Vernam Cipher
The Vernam Cipher, also known as the one-time pad, is a symmetric key cipher where the plaintext is combined with a random key of the same length.

**Formula**:
- For each letter in the plaintext \( P \) and key \( K \):
  
  \[
  C = (P XOR K) mod 26
  \]

Where \( \oplus \) denotes the XOR operation.

**Example**:
- Plaintext: `HELLO`
- Key: `XMCKL`
- Ciphertext: `KFRRQ`

### Autokey Cipher
The Autokey Cipher is a polyalphabetic cipher that uses a keyword followed by the plaintext itself to create the key.

**Formula**:
- For each letter in the plaintext \( P \) and key \( K \):
  
  \[
  C = (P + K) mod 26
  \]

Where the key is derived from the plaintext.

**Example**:
- Plaintext: `HELLO`
- Keyword: `KEY`
- Key: `KEYHEL`
- Ciphertext: `RIJVS`

### One-Time Pad
The One-Time Pad is a theoretically unbreakable cipher that uses a random key that is as long as the message itself. Each letter of the plaintext is combined with a corresponding letter of the key.

**Formula**:
- Similar to the Vernam Cipher:
  
  \[
  C = (P + K) mod 26
  \]

**Example**:
- Plaintext: `HELLO`
- Key: `XMCKL`
- Ciphertext: `ZEBRA`

## Transposition Ciphers

### Rail Fence Cipher
The Rail Fence Cipher is a form of transposition cipher that writes the plaintext in a zigzag pattern across multiple "rails" and reads off each line to create the ciphertext.

**Example**:
- Plaintext: `HELLO`
- Rails: `2`
- Ciphertext: `HLOEL`

### Columnar Transposition Cipher
In the Columnar Transposition Cipher, the plaintext is written into a grid and then rearranged based on a keyword. Each letter of the keyword represents a column, and the order of the keyword dictates the order in which to read the columns.

**Example**:
- Plaintext: `HELLO`
- Key: `HACK`
- Ciphertext: `HLOEL`

## Usage
To use the algorithms provided in this repository, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Cipher-Algorithms.git
   cd Cipher-Algorithms
## Note

As a learner exploring the fascinating world of cryptography, I have utilized multiple sources as references throughout this project. My goal is to create a comprehensive repository that consolidates various details and concepts in one place, making it easier for others to understand and explore these classical cipher techniques.

I appreciate the work of those who have contributed to the field and hope that this repository serves as a useful resource for anyone interested in learning about substitution and transposition ciphers. Your feedback and suggestions are welcome as I continue to learn and improve.

Thank you for visiting my repository!

