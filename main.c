#include <ctype.h>
#include <stdio.h>
char shift_char(char plain_letter, int shift_value) {
    int offset, k;
    int normalise_shift;

    normalise_shift = ((shift_value % 26) + 26) % 26;
    
    if (islower(plain_letter)) {
        offset = plain_letter - 'a';
        k = (offset + normalise_shift) % 26;
        return k+'a';

    } else if (isupper(plain_letter)) {

        offset = plain_letter - 'A';
        k = (offset + normalise_shift) % 26;
        return k + 'A';

    } else {
        return plain_letter;
    }
}

int main() {

    printf("%c\n", shift_char('a', 233));

    return 0;
}
