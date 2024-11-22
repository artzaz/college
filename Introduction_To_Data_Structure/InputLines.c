#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to store the word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function to find if the word already exists in the array
int findWordIndex(WordFrequency words[], int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;  // Word found, return its index
        }
    }
    return -1;  // Word not found
}

int main() {
    WordFrequency words[MAX_WORDS]; // Array to store words and their frequencies
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];

    printf("Enter words (Ctrl+D to end input):\n");

    // Reading words from input until EOF (Ctrl+D)
    while (scanf("%s", word) != EOF) {
        // Check if the word already exists in the array
        int index = findWordIndex(words, wordCount, word);

        if (index != -1) {
            // If the word exists, increment its count
            words[index].count++;
        } else {
            // If the word is new, add it to the array
            strcpy(words[wordCount].word, word);
            words[wordCount].count = 1;
            wordCount++;
        }
    }

    // Print the words and their frequencies
    printf("\nWord Frequency:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
