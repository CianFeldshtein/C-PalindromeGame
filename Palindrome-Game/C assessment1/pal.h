//
// Created by Cian on 22/02/2018.
//
#ifndef PAL_H_INCLUDED
#define PAL_H_INCLUDED
#include "Useful.h"

void displayState(int* pListOfNumbers, int  positionOfCursor, int number_of_digits);

void moveCursorRight(int* pPosOfCursor, int max);

void moveCursorLeft(int* pPosOfCursor);

void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor);

void decrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor);

boolean is_palindrome(int* plist_of_numbers, int size);

char get_command();

void processCommand(int* pList, int size, int* pPositionOfCursor, char command);

#endif
