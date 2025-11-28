#   RSA Encryption
#       needed public_key, private_key, e, n, phi of n, p, q
#
#       p,q = prime numbers
#       n, e = way to gen public key
#       phi_n = euler's totient
#       d, e = private key gen
#
#       eulers theorem: if x is prime, then x raised to the phi of n = 1 mod n
#
#       

import random
import math

def is_prime(number):
    if number < 2:
        return False
    for i in range(2, number // 2+1):
        if number % i == 0:
            return False
    return True

def generate_prime(min_value, max_value):
    prime = random.randint(min_value, max_value)
    while not is_prime(prime):
        prime = random.randint(min_value, max_value)
    return prime


def mod_inverse(e, phi):
    for d in range(3, phi):
        if (d * e) % phi == 1:
            return d
    raise ValueError("mod_inverse does not exist")

p, q = generate_prime(1000, 5000), generate_prime(1000, 5000)

while p == q:
    q = generate_prime(1000, 5000)
    
n = p * q
phi_n = (p-1) * (q-1)

e = random.randint(3, phi_n - 1)
while math.gcd(e, phi_n) != 1:
    e = random.randint(3, phi_n - 1)
    
d = mod_inverse(e, phi_n)

print("Public key: ", e)
print("Private Key: ", d)
print("n: ", n)
print("phi of n: ", phi_n)
print("p: ", p)
print("q: ", q)


message = "This is some text"

message_encoded = [ord(ch) for ch in message]

# (m ^ e) % n = c
ciphertext = [pow(ch, e, n) for ch in message_encoded]
print(ciphertext)

message_encoded = [pow(ch, d, n) for ch in ciphertext]
message = "".join(chr(ch) for ch in message_encoded)

print(message)