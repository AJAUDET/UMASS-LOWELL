#   EFFORT PER MEMBER
#
#   AJ: 33%
#   Lourenco: 33%
#   Bryan: 33%

from os import urandom 
import json 
from Crypto.Hash import SHA3_512
from Crypto.Protocol.KDF import PBKDF2

iterations = 100_000
key_length = 32

def create_salted_hash(password):
    salt = urandom(16)

    derived_key = PBKDF2(password, salt, dkLen=key_length, count=iterations, hmac_hash_module=SHA3_512)
    return json.dumps({
    "salt":salt.hex(),
    "hash":derived_key.hex()
})

def verify_password(stored_hash, password):
    data = json.loads(stored_hash)
    salt = bytes.fromhex(data["salt"])
    original_hash = data["hash"]

    derived_key = PBKDF2(password, salt, dkLen=key_length, count=iterations, hmac_hash_module=SHA3_512)
    return derived_key.hex() == original_hash


if __name__ == "__main__":
    my_password = "1qazxsW@1"
    alt_password = "1qazxsw@1"
    
   #test case (uppercase W)
    password_hash = create_salted_hash(my_password)
    print(f"Hashed Password: {password_hash}")
    if verify_password(password_hash, my_password):
        print("Access Granted")
    else:
        print("Access Denied")
    
    #test case (lowercase w)
    password_hash = create_salted_hash(alt_password)
    print(f"Hashed Password: {password_hash}")
    if verify_password(password_hash, alt_password):
        print("Access Granted")
    else:
        print("Access Denied")