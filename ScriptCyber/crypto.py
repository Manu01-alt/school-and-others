from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import datetime
import json
import os

KEY = os.urandom(16)

username = "Am"+"?"*32+"ministratore"
token = {"username" : username, "registration_date" : str(datetime.date.today())}
token_json = json.dumps(token).encode()
token_blocks = [token_json[i:i+16] for i in range(0,48,16)]

for block in token_blocks:
    print(block)

cipher = AES.new(KEY, AES.MODE_ECB)
encrypted_token = "dc9a9174a06faf1deae74f0062250aae7f4e3060e6ac4664ef6f1c2c7de699f300c1aa6a161f582cbccf8563bef5b1bfef0854772e4360f6f91c953276f72f89c7e8099423da78b60246d3c8251ef7eb"
et_blocks = [encrypted_token[i:i+32] for i in range(0,96,32)]

for block in et_blocks: 
    print(block)


