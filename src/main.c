#include <ctype.h>
#include <stdio.h>

#define BUFFER_LIMIT 1000
char shift_char(char plain_letter, int shift_value) {
    int offset, k;
    int normalise_shift;

    normalise_shift = ((shift_value % 26) + 26) % 26;

    if (islower(plain_letter)) {
        offset = plain_letter - 'a';
        k = (offset + normalise_shift) % 26;
        return k + 'a';

    } else if (isupper(plain_letter)) {

        offset = plain_letter - 'A';
        k = (offset + normalise_shift) % 26;
        return k + 'A';

    } else {
        return plain_letter;
    }
}

void cipher_string(const char *input, char *output, int shift_value){
    while (*input != '\0'){
        *output = shift_char(*input, shift_value);
        output++;
        input++;
    }
    *output = '\0';
}

int main() {
    char plaintext [] = "dani is a kooni";
    char ciphertext [BUFFER_LIMIT];
    char ciphertext2 [BUFFER_LIMIT] ;
    cipher_string(plaintext, ciphertext, 6);

    printf("%s\n", ciphertext);
    cipher_string(ciphertext, ciphertext2, -6);

    printf("%s\n", ciphertext2);
    return 0;
}
