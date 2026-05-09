#include <ctype.h>
#include <stdio.h>
#define ALPHABET_COUNT 26
void count_frequencies(const char *text, int freq[ALPHABET_COUNT]) {

    while (*text != '\0') {
        if (isalpha(*text)) {
            freq[tolower(*text) - 'a']++;
            text++;
        } else {
            text++;
        }
    }
}

int main() {
    int i;
    int freq[ALPHABET_COUNT] = {0};
    char lower_alphabet[ALPHABET_COUNT] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                               'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                               'w', 'x', 'y', 'z'};
    char plaintext[] = "dani is a gav";

    count_frequencies(plaintext, freq);
    for (i = 0; i < 26; i++) {
        if (freq[i] != 0)
            printf("%c: %d\n", lower_alphabet[i], freq[i]);
    }
    return 0;
}
