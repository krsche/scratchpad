#include <stdio.h>

int hexstring_to_bytes(const char *input, size_t inputsize, char *output) {
    const char *current_pos = input;
    size_t i;
    
    for (i = 0; i < inputsize/2; i++){
        sscanf(current_pos, "%2hhx", &output[i]);
        current_pos += 2;
    }
    return 0;
}

int bytes_to_hexstring(const char *input, size_t inputsize, char *output) {
    char *current_pos = output;
    
    for (size_t i = 0; i < inputsize; i++){
        sprintf(current_pos, "%2x", input[i]);
        current_pos += 2;
        // break;
    }
    // *current_pos = '\0';
    // *current_pos = 'a';
    // current_pos -= 2;
    // printf("current_pos value being pointed to:   %c \n", *current_pos);
    // printf("current_pos address being pointed to: %p \n", current_pos);
    // printf("current_pos address of pointer:       %p \n", &current_pos);
    printf("%s\n", output);
    return 0;
}

int main() {
    #define BUFFERSIZE 36/2

    const char input_hex[] = "1c0111001f010100061a024b53535009181c";
    const char modifier_hex[] = "686974207468652062756c6c277320657965";
    char input_bytes[BUFFERSIZE];
    char modifier_bytes[BUFFERSIZE];
    char xor_result_bytes[BUFFERSIZE];
    char xor_result_hex[BUFFERSIZE*2];

    hexstring_to_bytes(input_hex, sizeof(input_hex), input_bytes);
    hexstring_to_bytes(modifier_hex, sizeof(modifier_hex), modifier_bytes);

    size_t i;
    for (i = 0; i < BUFFERSIZE; i++) {
        xor_result_bytes[i] = input_bytes[i] ^ modifier_bytes[i];
    }

    bytes_to_hexstring(xor_result_bytes, i, xor_result_hex);
    
    printf("input_hex:        %s\n", input_hex);
    printf("modifier_hex:     %s\n", modifier_hex);
    printf("input_bytes:      %s\n", input_bytes);
    printf("modifier_bytes:   %s\n", modifier_bytes);
    printf("xor_result_bytes: %s\n", xor_result_bytes);
    printf("xor_result_hex:   %s\n", xor_result_hex);

    return 0;
}

