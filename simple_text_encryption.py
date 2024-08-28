def char_to_number(c):
    """Convert a character to its corresponding number (A=1, B=2, ..., Z=26)."""
    return ord(c.upper()) - ord('A') + 1

def number_to_char(num):
    """Convert a number back to a character (1=A, 2=B, ..., 26=Z)."""
    return chr((num - 1) % 26 + ord('A'))

def convert_key_to_numbers(key):
    """Convert the key string into a list of numbers."""
    key_numbers = []
    for c in key:
        if c.isalpha():
            key_numbers.append(char_to_number(c))
    return key_numbers

def encrypt_message(message, key_numbers):
    """Encrypt the message using the key."""
    encrypted_message = ""

    for i, c in enumerate(message):
        if c.isalpha():
            message_num = char_to_number(c)
            key_num = key_numbers[i % len(key_numbers)]
            encrypted_num = message_num + key_num
            encrypted_message += number_to_char(encrypted_num)
        else:
            encrypted_message += c  # Non-alphabetic characters remain unchanged

    return encrypted_message

def decrypt_message(encrypted_message, key_numbers):
    """Decrypt the message using the key."""
    decrypted_message = ""

    for i, c in enumerate(encrypted_message):
        if c.isalpha():
            encrypted_num = char_to_number(c)
            key_num = key_numbers[i % len(key_numbers)]
            decrypted_num = encrypted_num - key_num
            if decrypted_num <= 0:
                decrypted_num += 26  # Ensure the number stays within the alphabet range
            decrypted_message += number_to_char(decrypted_num)
        else:
            decrypted_message += c  # Non-alphabetic characters remain unchanged

    return decrypted_message

def main():
    key = input("Enter the key: ")
    message = input("Enter the message to encrypt: ")

    # Convert the key into numbers
    key_numbers = convert_key_to_numbers(key)

    # Encrypt the message
    encrypted_message = encrypt_message(message, key_numbers)
    print("Encrypted Message:", encrypted_message)

    # Decrypt the message
    decrypted_message = decrypt_message(encrypted_message, key_numbers)
    print("Decrypted Message:", decrypted_message)

if __name__ == "__main__":
    main()
