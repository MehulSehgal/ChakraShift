def encrypt(text, shift):
    result = ""
    for char in text:
        if char.isalpha():
            base = 65 if char.isupper() else 97
            result += chr((ord(char) - base + shift) % 26 + base)
        else:
            result += char
    return result
def decrypt(text, shift):
    return encrypt(text, -shift)
def main():
    print("=" * 50)
    print("     Caesar Cipher - Encryption & Decryption")
    print("=" * 50)

    message = input("\nEnter the message: ")
    shift = int(input("Enter shift key (1-25): "))

    encrypted = encrypt(message, shift)
    decrypted = decrypt(encrypted, shift)

    print("\n" + "-" * 50)
    print(f"Original  : {message}")
    print(f"Encrypted : {encrypted}")
    print(f"Decrypted : {decrypted}")
    print("-" * 50)


if __name__ == "__main__":
    main()
