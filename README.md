# Caesar Cipher — DecodeLabs Cyber Security Project 2

Basic Encryption & Decryption using the Caesar Cipher, implemented in Python, C, C++, and as a browser-based web app.

---

## What It Does

Takes a plaintext message and a shift key, shifts each letter by that amount through the alphabet, and produces ciphertext. Decryption reverses the process using the same key (symmetric encryption).

**Encrypt:** `E(x) = (x + n) % 26`  
**Decrypt:** `D(x) = (x - n) % 26`

Spaces, numbers, and punctuation are passed through unchanged.

---

## Project Structure

```
caesar_cipher/
├── python/
│   └── caesar_cipher.py
├── cpp/
│   └── caesar_cipher.cpp
├── c/
│   └── caesar_cipher.c
└── web/
    ├── index.html
    ├── style.css
    └── script.js
```

---

## How to Run

### Python
```bash
cd python
python caesar_cipher.py
```
Requires Python 3.x. No external libraries needed.

---

### C++
```bash
cd cpp
g++ caesar_cipher.cpp -o caesar_cipher
./caesar_cipher
```

---

### C
```bash
cd c
gcc caesar_cipher.c -o caesar_cipher
./caesar_cipher
```

---

### Web (HTML/CSS/JS)
Open `web/index.html` directly in any browser. No server required.

---

## Example

```
Enter the message: Hello World
Enter shift key (1-25): 3

Original  : Hello World
Encrypted : Khoor Zruog
Decrypted : Hello World
```

---

## Key Concepts Covered

- ASCII-based character manipulation using `ord()` / `chr()` in Python, and direct casting in C/C++
- Modular arithmetic (`% 26`) to wrap the alphabet circularly
- Symmetric encryption — the same key is used to both encrypt and decrypt
- Edge case handling for spaces, punctuation, and mixed case

---

## Known Limitation

The Caesar cipher has only 25 possible keys, making it trivially breakable by brute force or frequency analysis. It is a learning tool, not a production-grade encryption method. Modern systems use AES-256 with keys of 2^256 possible values.

---

## Project Info

**Batch:** 2026  
**Organization:** DecodeLabs  
**Domain:** Cyber Security  
**Track:** Basic Encryption & Decryption
