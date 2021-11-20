import base64

input_string_hex="49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
byte_array = bytearray.fromhex(input_string_hex)

print("As HEX:                  " + input_string_hex)
print("As ASCII:                " + byte_array.decode())
print("As base64 encoded ASCII: " + base64.b64encode(byte_array).decode())
