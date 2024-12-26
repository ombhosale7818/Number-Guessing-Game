#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void number_guessing_game() {
    int secret_number, guess, attempts = 0, max_attempts = 10;

    // Initialize random number generator
    srand(time(NULL));
    
    // Generate a random number between 1 and 100
    secret_number = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess the number.\n\n", max_attempts);

    // Game loop: give the player 10 attempts to guess the number
    while (attempts < max_attempts) {
        printf("Attempt %d/%d: Enter your guess: ", attempts + 1, max_attempts);
        if (scanf("%d", &guess) != 1) {
            // Handle invalid input
            while(getchar() != '\n'); // clear input buffer
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        attempts++;

        if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the correct number %d in %d attempts.\n", secret_number, attempts);
            break;
        }
    }

    if (guess != secret_number) {
        printf("Sorry, you've used all your attempts. The correct number was %d.\n", secret_number);
    }
}

int main() {
    // Start the game
    number_guessing_game();
    return 0;
}
