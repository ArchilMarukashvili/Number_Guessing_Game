#include <stdio.h> //Basic input-output library, needed for printf() and scanf()
#include <stdlib.h> //General library needed for rand() and srand()
#include <time.h> //Library needed to seed the random number generator

int main() {
    int number, guess, attempts = 0; //Declaring 3 variables, with attempts being the only one initialized to 0
    srand(time(0));
    number = rand() % 100 + 1;

    printf("Guess the number between 1 and 100\n");

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

    } while (guess != number); //repeats loop until correct guess

    return 0;
}

//In order to run the code, first compile it with:
// gcc main.c -o main.exe

//Then execute the compiled program with:
// .\main.exe