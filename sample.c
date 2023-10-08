#include <stdio.h>

int count_word_occurrences(const char* haystack, const char* needle) {
    int count = 0;
    size_t needle_length = strlen(needle);

    // Iterate through the string until no more occurrences are found
    for (const char* ptr = haystack; (ptr = strstr(ptr, needle)) != NULL; ++ptr) {
        // Increment the count
        ++count;
        // Move the pointer forward by the length of the needle to avoid counting the same occurrence multiple times
        ptr += needle_length - 1;
    }

    return count;
}

int main() {
    const char* str = "This is a sample string. Sample is the keyword. Another sample.";
    const char* word = "sample";

    int occurrences = count_word_occurrences(str, word);

    printf("The word '%s' occurs %d times.\n", word, occurrences);

    return 0;
}
