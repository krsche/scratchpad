import base64

input_string_hex = "1c0111001f010100061a024b53535009181c"

first = bytearray.fromhex(input_string_hex)
second = bytearray.fromhex("686974207468652062756c6c277320657965")

result = b''
for i in range(len(first.decode())):
    r = first[i] ^ second[i]
    result += r.to_bytes(1, 'big')

print(result.decode())
print(result.hex())