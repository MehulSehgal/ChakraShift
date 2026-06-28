#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift, char *result) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            result[i] = (char)(((text[i] - base + shift) % 26 + 26) % 26 + base);
        } else {
            result[i] = text[i];
        }
    }
    result[len] = '\0';
}

void decrypt(char *text, int shift, char *result) {
    encrypt(text, -shift, result);
}

int main() {
    char message[256];
    char encrypted[256];
    char decrypted[256];
    int shift;

    printf("==================================================\n");
    printf("     Caesar Cipher - Encryption & Decryption\n");
    printf("==================================================\n");

    printf("\nEnter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter shift key (1-25): ");
    scanf("%d", &shift);

    encrypt(message, shift, encrypted);
    decrypt(encrypted, shift, decrypted);

    printf("\n--------------------------------------------------\n");
    printf("Original  : %s\n", message);
    printf("Encrypted : %s\n", encrypted);
    printf("Decrypted : %s\n", decrypted);
    printf("--------------------------------------------------\n");

    return 0;
}
