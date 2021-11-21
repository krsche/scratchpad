import itertools

def xor(base, modifier):
    if len(base) > len(modifier):
        n = len(modifier)
        print("dropping " + base[len(modifier):].decode() + " from base bytes")
    else:
        n = len(base)

    result = b''
    for i in range(n):
        r = base[i] ^ modifier[i]
        result += r.to_bytes(1, 'big')

    return result

def duplicate_bytes(input, size):
    result = b''
    for i in range(size):
        result += input
    return result

if __name__ == '__main__':
    input_hex = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
    input_bytes = bytearray.fromhex(input_hex)
    
    print("input_bytes: " + input_bytes.decode())

    cases = {}

    for i in itertools.chain(range(65,90), range(97, 122)):
        cases[chr(i)] = xor(input_bytes, duplicate_bytes(i.to_bytes(1, 'big'), len(input_bytes))).decode()

    #print(cases)

    


