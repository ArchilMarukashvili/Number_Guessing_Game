#include <stdio.h>   // Basic input-output library, needed for printf() and scanf()
#include <stdlib.h>  // General library needed for rand() and srand()
#include <time.h>    // Library needed to seed the random number generator

int main() {
    int number, guess, attempts = 0; // Declaring variables, initializing attempts to 0
    int level, max; // Variables for difficulty selection

    // Ask for difficulty level
    printf("Select difficulty: 1 = Easy (1-50), 2 = Medium (1-100), 3 = Hard (1-500): ");
    scanf("%d", &level); //scanf pauses program, waits for user input, %d tells program to make sure input is a base 10 value,
    // and then assigns whatever number is inputted to the memory address of level

    // Determine number range based on chosen difficulty
    switch (level) {
        case 1: max = 50;  break;
        case 2: max = 100; break;
        case 3: max = 500; break;
        default:
            printf("Invalid choice. Defaulting to Medium (1-100).\n"); //If invalid input entered, automatically set difficulty to medium

            max = 100;
            break;
    }

    srand(time(0));           // Seed the random number generator
    number = rand() % max + 1; // Generate random number within chosen range, we add +1 because range begins from 0

    printf("Guess the number between 1 and %d\n", max);


    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number)
            printf("Too high!\n");
        else if (guess < number)
            printf("Too low!\n");
        else
            printf("Correct! You guessed it in %d attempts.\n", attempts);

    } while (guess != number); // Repeat until the correct guess

    return 0;
}

// You'll need to compile the code first using a C compiler like GCC, everytime prorgram is edited:
// gcc main.c -o main.exe
// Then to simply run it you run:
// .\main.exe
