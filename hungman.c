#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_WRONG_GUESSES 6

int main() {
    char word[MAX_WORD_LENGTH];
    char guessedLetters[MAX_WORD_LENGTH];
    int numWrongGuesses = 0;
    int numCorrectGuesses = 0;
    int wordLength;
    int i, j, found;

    printf("Welcome to Hangman!\n");
    printf("Player 1, enter the word to be guessed (up to %d characters): ", MAX_WORD_LENGTH);
    scanf("%s", word);

    wordLength = strlen(word);
    for (i = 0; i < wordLength; i++) {
        word[i] = tolower(word[i]);
        guessedLetters[i] = '_';
    }

    guessedLetters[wordLength] = '\0';

    while (numWrongGuesses < MAX_WRONG_GUESSES && numCorrectGuesses < wordLength) {
        char guess;

        printf("\n");
        printf("Word: %s\n", guessedLetters);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        guess = tolower(guess);

        found = 0;
        for (i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                if (guessedLetters[i] == '_') {
                    guessedLetters[i] = guess;
                    numCorrectGuesses++;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("Wrong guess!\n");
            numWrongGuesses++;
        }
    }

    if (numCorrectGuesses == wordLength) {
        printf("\n");
        printf("Congratulations! You guessed the word: %s\n", word);
    } else {
        printf("\n");
        printf("Sorry, you lost! The word was: %s\n", word);
    }

    return 0;
}
