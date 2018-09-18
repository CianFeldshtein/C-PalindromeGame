//
// Created by Cian on 22/02/2018.
//
#include <stdio.h>
#include <mem.h>
#include "Useful.h"
void displayState(int* pListOfNumbers, int  positionOfCursor, int number_of_digits)
{
    int n;
    char character[] = "Game State:\t<";
    int l = strlen(character)+2; //Stores the length to calculate the spaces to go through
    printf(" \n\n%s",character); // prints out game state

    for (n = 0; n < number_of_digits; n++)  //loops to print each number
        printf("%2d", *(pListOfNumbers + n)); //Prints the numbers in the list
    printf(" >\t\tCursor at %d\n", positionOfCursor); // Prints position of cursor

    for (n = 0; n < l; n++)
        printf(" "); //Prints the number of spaces as the length of 'c'

    for (n = -1; n < positionOfCursor; n++)
        printf("  ");
        printf(" ^\n");
}

void moveCursorRight(int* pPosOfCursor, int max)
{
    if (*(pPosOfCursor) < (max-1)) //if position of cursor is not at end of list
        (*pPosOfCursor)+=1; //Moves cursor one space to the right if there is a space to move right in the list
    else
        printf(" Invalid Move: Can't move cursor Right"); // error message if you are at end of list
}

void moveCursorLeft(int* pPosOfCursor)
{
    if (*(pPosOfCursor) > 0) //if position of the cursor is not at first position in the list
        (*pPosOfCursor) -=1; // moves cursor one space to the left if there is a possible move for moving left
    else
        printf(" Invalid Move: Can't move cursor Left");
}

void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor)
{
    if(*(pListOfNumbers + positionOfCursor)<9) //if number is less than 9, then increment it
        *(pListOfNumbers + positionOfCursor) = *(pListOfNumbers + positionOfCursor)+1;
    else
        printf("Invalid Move, number cannot be greater than 9!"); // the user cannot enter a number which is greater than 9
}

void decrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor)
{
    if (*(pListOfNumbers + positionOfCursor) > 0) //if value of number is greater than 0, decrement it
        *(pListOfNumbers + positionOfCursor) = *(pListOfNumbers + positionOfCursor) - 1;
    else
        printf("Invalid Move, enter number greater than 0!"); // the user cannot enter a number less than 0
}

boolean is_palindrome(int* plist_of_numbers, int size)
{
    int forward = 0; //forward loop
    int backward = 0; // backward loop
    boolean checkTrue = True;

        for (forward = 0, backward = (size - 1); forward < size/2 && backward>((size/2)-1); forward++, backward--) //Traversing the list from the front and back of list.
        {
            if (*(plist_of_numbers + forward) == *(plist_of_numbers + backward)) //first element equals to the last element
            {
                continue;
            }
            else
                checkTrue = False; //not a palindrome list
        }
    return checkTrue; // returns whether list is a palindrome list or not
}

char get_command()
{
    char command;
    char  validCharacters[] = { 'a','d','w','x' };
    int n = 0;
    do
    {
        if (n == 0)
        {
            printf(" \na - Move Cursor Left\nd - Move Cursor Right\nw - Increment\nx - Decrement\n");
            printf("Enter a valid command:\t");
            command = my_get_char(); //Gets command from my_get_char method in useful.c
            if (command == '\n')
                command = my_get_char();
            if (command == validCharacters[0]) // command is 'a' as 'a' is at index 0
                n = 1;
            else if (command == validCharacters[1]) // command is 'd' as 'd' is at index 1
                n = 1;
            else if (command == validCharacters[2]) // command is 'w' as 'w' is at index 2
                n = 1;
            else if (command == validCharacters[3]) // // command is 'x' as 'x' is at index 3
                n = 1;
        }
        else
            break; // invalid input - need to choose from valid characters
    } while (n == 0);
    return command;
}

void processCommand(int* pList, int size, int* pPositionOfCursor, char command)
{
        if (command == 'a') {//Function of 'a' is to move cursor left
            moveCursorLeft(pPositionOfCursor);
        }
        else if (command == 'd'){//Function of 'd' is to move cursor right
            moveCursorRight(pPositionOfCursor, size);
        }
        else if (command == 'w') {//Function of 'w' is to increment the value at the cursor
            incrementDigitInListAtPos(pList, *pPositionOfCursor);
        }
        else if (command == 'x') {//Function of 'x' is to decrement the value at the cursor
            decrementDigitInListAtPos(pList, *pPositionOfCursor);
        }
}



