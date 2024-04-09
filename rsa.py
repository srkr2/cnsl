import math
import random

def gcd(a, h):
    temp = 0
    while(1):
        temp = a % h
        if (temp == 0):
            return h
        a = h
        h = temp

# Taking input from the user
p = int(input("Enter a prime number (p): "))
q = int(input("Enter another prime number (q): "))
n = p * q
phi = (p - 1) * (q - 1)
print("phi(p-1*q-1)= ", phi)

def generate_e(phi):
    valid_e_values = []
    for e in range(2, phi):
        if gcd(e, phi) == 1:
            valid_e_values.append(e)
    return valid_e_values

valid_e_values = generate_e(phi)

# if not valid_e_values:
#     print("No valid 'e' values found. Please choose different prime numbers.")
#     exit()

print("Possible 'e' values:", valid_e_values)

# Letting the user choose 'e' from the list of valid values
# while True:
#     e_choice = int(input("Choose one of the possible 'e' values: "))
    # if e_choice not in valid_e_values:
    #     print("Invalid choice. Please select one of the possible 'e' values.")
    #     continue
    # break
e_choice = int(input("Choose one of the possible 'e' values: "))
# Generate d
def generate_d(e, phi):
    k = 0
    while True:
        d = (1 + (k * phi)) / e
        if d.is_integer():
            return int(d)
        k += 1
d = generate_d(e_choice, phi)

# Message to be encrypted
msg = int(input("Enter the message to be encrypted: "))

print("Message data = ", msg)

# Encryption c = (msg ^ e) % n
c = pow(msg, e_choice, n)
print("Encrypted data = ", c)

# Decryption m = (c ^ d) % n

m = pow(c, d, n)
print("Original Message Sent = ", m)

