//
// Created by Cian on 22/02/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pal.h"

void start_game()
{
    int number_of_digits='a';
    int positionOfCursor = 0;
    int numberOfGoes = 0;

    printf(" Enter the Size Of the Palindrome List:\t"); // asks user for size of palindrome
    while (scanf(" %d", &number_of_digits) != 1) // validating that its a number and not any other sort of input
    {
        char ch = my_get_char();
        printf("The input you have entered is ' "); // Returns error message for incorrect input
        putchar(ch);
        printf("', please enter valid input!");

        while (my_get_char() != '\n'); //stops infinite loop

        printf("\nEnter the Size Of the Palindrome List\n");
    }

    srand(time(NULL)); // makes sure different set of numbers is always printed
    positionOfCursor = rand() % number_of_digits; // selects a random position for positionOfCursor
    int* pNumbers = (int*)malloc(sizeof(int)*number_of_digits); //allocate memory for 6 numbers
    int y;
    srand(time(NULL));
    for (y = 0; y < number_of_digits; y++) //Loops for size of game
        *(pNumbers + y) = rand() % 10; // numbers are randomized

    printf(" Position Of The Cursor is %d\n", positionOfCursor);
    printf(" Address Of The Pointer to the List is %p\n", pNumbers);
    printf("\nTEST PURPOSES\n"); // Testing for moving cursor left, moving cursor right
                                // incrementing, decrementing and checking for a palindrome
    displayState(pNumbers, positionOfCursor, number_of_digits);
    moveCursorLeft(&positionOfCursor);

    displayState(pNumbers, positionOfCursor, number_of_digits);
    moveCursorLeft(&positionOfCursor);

    displayState(pNumbers, positionOfCursor, number_of_digits);
    moveCursorRight(&positionOfCursor, number_of_digits);

    displayState(pNumbers, positionOfCursor, number_of_digits);
    moveCursorRight(&positionOfCursor, number_of_digits);

    displayState(pNumbers, positionOfCursor, number_of_digits);
    incrementDigitInListAtPos(pNumbers, positionOfCursor);

    displayState(pNumbers, positionOfCursor, number_of_digits);
    incrementDigitInListAtPos(pNumbers, positionOfCursor);

    displayState(pNumbers, positionOfCursor, number_of_digits);
    decrementDigitInListAtPos(pNumbers, positionOfCursor);

    displayState(pNumbers, positionOfCursor, number_of_digits);
    decrementDigitInListAtPos(pNumbers, positionOfCursor);

    displayState(pNumbers, positionOfCursor, number_of_digits);
    int size = (sizeof(int)*number_of_digits) / sizeof(*(pNumbers+0));
    boolean false = is_palindrome(pNumbers, size);
    printf(" \t\tPalindrome: %s", (false) ? "True" : "False"); // prints if palindrome is either true or false
    char command;
    while (false == 0) //while false
    {
        displayState(pNumbers, positionOfCursor, number_of_digits); // displays state of the game
        command = get_command(); // gets the char inputed
        processCommand(pNumbers, size, &positionOfCursor, command); // manages the commands
        false = is_palindrome(pNumbers, size); // checks to see if you make a palindrome
        numberOfGoes += 1; // increments your number of goes in making a palindrome by one each time you guess
    }
    displayState(pNumbers, positionOfCursor, number_of_digits);
    printf(" \n Excellent Job! You've created a Palindrome List.\n The number Of goes taken to complete palindrome was: %d\n", numberOfGoes); // num of goes taken to get palindrome
    free(pNumbers); //deallocates the memory previously allocated by a call to malloc.
}
int main()
{
    start_game(); // starts the game
    return 0;
}