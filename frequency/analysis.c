#include <ctype.h>
#include <stdio.h>
#define ALPHABET_COUNT 26
void count_frequencies(const char *text, int freq[ALPHABET_COUNT]) {

    while (*text != '\0') {
        if (isalpha(*text))
            freq[tolower(*text) - 'a']++;
        text++;
    }
}

int main() {
    int i;
    int freq[ALPHABET_COUNT] = {0};
    char plaintext[] = "dani is a gav";

    count_frequencies(plaintext, freq);
    for (i = 0; i < ALPHABET_COUNT; i++) {
        if (freq[i] != 0)
            printf("%c: %d\n", 'a' + i, freq[i]);
    }
    return 0;
}
