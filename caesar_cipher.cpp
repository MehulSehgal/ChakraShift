#include <iostream>
#include <string>
std::string encrypt(std::string text, int shift) {
    std::string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char)(((c - base + shift) % 26 + 26) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

std::string decrypt(std::string text, int shift) {
    return encrypt(text, -shift);
}

int main() {
    std::string message;
    int shift;

    std::cout << std::string(50, '=') << std::endl;
    std::cout << "     Caesar Cipher - Encryption & Decryption" << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    std::cout << "\nEnter the message: ";
    std::getline(std::cin, message);

    std::cout << "Enter shift key (1-25): ";
    std::cin >> shift;

    std::string encrypted = encrypt(message, shift);
    std::string decrypted = decrypt(encrypted, shift);

    std::cout << "\n" << std::string(50, '-') << std::endl;
    std::cout << "Original  : " << message << std::endl;
    std::cout << "Encrypted : " << encrypted << std::endl;
    std::cout << "Decrypted : " << decrypted << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    return 0;
}
