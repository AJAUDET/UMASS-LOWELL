#   Name : AJ Audet
#   Date : 10/19/2025
#   Purpose : encrypt and decrypt files using PGP principles
#   Time Spent : 3 hours

import sys
from Crypto.Random import get_random_bytes
from Crypto.PublicKey import RSA
from Crypto.Cipher import AES, PKCS1_OAEP

def encrypt(public_key_file, inFile, outFile):
    # read recipients public key
    with open(public_key_file, 'rb') as pub:
        recipient_key = RSA.import_key(pub.read())
    # generate a session key for the encryption
    session_key = get_random_bytes(16)
    
    # generate a RSA Cipher using PKCS1
    RSA_cipher = PKCS1_OAEP.new(recipient_key)
    encrypted_session_key = RSA_cipher.encrypt(session_key)
    
    # read the information in the unencrypted file and store it
    with open(inFile, 'rb') as inF:
        plaintext = inF.read()
    
    # encrypt using AES
    AES_cipher = AES.new(session_key, AES.MODE_GCM)
    ciphertext, tag = AES_cipher.encrypt_and_digest(plaintext)
    
    # write to the output file the ciphertext, the nonce, encrypted session key, and the tag
    with open(outFile, 'wb') as outF:
        [outF.write(x) for x in (encrypted_session_key, AES_cipher.nonce, tag, ciphertext)]
    print(f"Encryption Successful")

def decrypt(private_key_file, inFile, outFile):
    # read the given private key
    with open(private_key_file, 'rb') as priv:
        private_key = RSA.import_key(priv.read())
    
    # read the encrypted session key, nonce, tag, and ciphertext from the encrypted file
    with open(inFile, 'rb') as inF:
        encrypted_session_key = inF.read(private_key.size_in_bytes())
        nonce = inF.read(16)
        tag = inF.read(16)
        ciphertext = inF.read()
    # create a new RSA Cipher using the private key
    RSA_cipher = PKCS1_OAEP.new(private_key)
    
    # decrypt the session key
    session_key = RSA_cipher.decrypt(encrypted_session_key)
    
    # decrypt the message using AES
    AES_cipher = AES.new(session_key, AES.MODE_GCM, nonce)
    plaintext = AES_cipher.decrypt_and_verify(ciphertext, tag)
    
    with open(outFile, 'wb') as outF:
        outF.write(plaintext)
    print(f"Decryption Successful")

if __name__ == '__main__':
    if (len(sys.argv) != 5):
        print(f"Usage:")
        print(f"\tpython3 fcrypt.py --encrypt <public key> <inFile> <outFile>")
        print(f"\tpython3 fcrypt.py --decrypt <private key> <inFile> <outFile>")
        sys.exit(1)

    mode = sys.argv[1]
    key = sys.argv[2]
    inFile = sys.argv[3]
    outFile = sys.argv[4]
    
    if mode == '--encrypt':
        encrypt(key, inFile, outFile)
    elif mode == '--decrypt':
        decrypt(key, inFile, outFile)
    else:
        print(f"Invalid mode given")
